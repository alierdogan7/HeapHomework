#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

#include "Task.h"
#include "Servers.h"
#include "Heap.h"

bool loadTasks( char *fileName, Task **&tasks, int& tasksNumber );

int main(int argc, char *argv[]) {

    // args[0] is ./simulator thing, args[1] is filename, args[2] is avgwaitingtime

     if(argc != 3){
        cout << "Wrong arguments!" << endl;
        return -1;
    }

    Task **tasks;
    int tasksNumber = 0;
    Heap heap;

    if( !loadTasks(argv[1], tasks, tasksNumber) )
        return -1;

    //for( int i = 0; i < tasksNumber; i++) tasks[i]->show();
    bool isFound = false;
    for(int serverNumber = 1; !isFound; serverNumber++)
    {
        Servers servers(serverNumber); //configure a new server room

        int taskCount = 0;
        for(int time = 0; taskCount < tasksNumber; time++) //simulate the time
        {
            if( tasks[taskCount]->getRequestTime() == time ) //if a request comes, insert it to priority queue
            {
                heap.heapInsert(tasks[taskCount]);
                taskCount++;
            }

            if( !servers.allServersBusy() ) //if there is any suitable server, process a request
            {
                Task *tmp = NULL;
                heap.heapDelete( tmp); //retrieve the most prior item from queue

                if ( tmp != NULL )
                {
                    servers.process(tmp, time); //process the request with a suitable computer
                }
            }

            servers.update(); //update all servers' times and states

        }
    }

    return 0;
}

bool loadTasks( char *fileName, Task **&tasks, int& tasksNumber )
{

    ifstream myFile(fileName);
    string line("");

    if ( !myFile.is_open() )
    {
        cout << "Unable to open file" << endl;
        return false;
    }
    else
    {
        getline(myFile, line);
        int size = atoi( line.c_str() ); //get size from first line
        int count = 0;

        tasks = new Task*[size];
        tasksNumber = size;

        while ( count < size && getline(myFile, line) )
        {
            string temp("");
            Task *tmpTask = new Task();

            // first one is ID
            int blankPos = line.find_first_of(" ");
            temp = line.substr(0, blankPos);
            line = line.substr(blankPos + 1);
            tmpTask->setId( atoi( temp.c_str() ) );

            //second one is PRIORITY
            blankPos = line.find_first_of(" ");
            temp = line.substr(0, blankPos);
            line = line.substr(blankPos + 1);
            tmpTask->setPriority( atoi( temp.c_str() ) );

            //third one is REQUEST TIME
            blankPos = line.find_first_of(" ");
            temp = line.substr(0, blankPos);
            line = line.substr(blankPos + 1);
            tmpTask->setRequestTime( atoi( temp.c_str() ) );

            //fourth one is PROCESS TIME
            blankPos = line.find_first_of("\n");
            temp = line.substr(0, blankPos);
            tmpTask->setProcessTime( atoi( temp.c_str() ) );

            //tmpTask->show();
            tasks[count] = tmpTask;
            count++;

        } //end of while loop

        myFile.close();
        return true;
    }
}
