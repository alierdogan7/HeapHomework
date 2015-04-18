/*
Ali Burak ERDOĞAN
21301492
CS202 - Section 3
Homework#3
*/

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

    //loading all the tasks from input file to an array
    if( !loadTasks(argv[1], tasks, tasksNumber) )
        return -1;
//    else
//       for( int i = 0; i < tasksNumber; i++) tasks[i]->show();

    //starting to simulate, server number starts from 1
    int serverNumber = 1;
    while(true)
    {
        Servers servers(serverNumber); //configure a new server room

        int taskCount = 0;
        for(int time = 0; taskCount < tasksNumber || !servers.allServersEmpty() || !heap.heapIsEmpty(); time++) //simulate the time
        {
            //insert all the requests which are coming at the same time
            while(taskCount < tasksNumber && tasks[taskCount]->getRequestTime() == time)
            {
                heap.heapInsert(tasks[taskCount]);
                taskCount++;
            }

            //unless all servers are busy, try to load each server with a request which is pulled from priority queue
            while( !servers.allServersBusy() && !heap.heapIsEmpty()) //if there is any suitable server, process a request
            {
                Task *tmp = NULL;
                heap.heapDelete( tmp); //retrieve the most prior item from queue

                if ( tmp != NULL )
                {
                    servers.process(tmp, time); //process the request with a suitable computer
                }
            }

            servers.update(); //update all servers' times and states

            //cout << "With serverNumber " << serverNumber << " at ms " << time << endl;
            //cout << servers.getLog() << endl;
        }

        //if avg. waiting is less than the limit, print the log and exit the loop
        double avgWaiting = servers.getTotalWaiting() / (double) tasksNumber;
        if(avgWaiting <= atoi(argv[2]) )
        {
            //heap.printHeap();
            cout << servers.getLog() << endl;
            cout << "Average waiting time: " << avgWaiting << " ms." << endl;
            break;
        }
        else
        {
            serverNumber++;
        }
    }


    return 0;
}

//loading all the tasks from input file to an array
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

        //generate new Task array
        tasks = new Task*[size];
        tasksNumber = size;

        //this loop simply parses each line and generates a Task object
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
