#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

#include "Task.h"

int main(int argc, char *argv[]) {
// args[0] is filename, args[1] is avgwaitingtime

    if(argc != 2){
        //cout << "Wrong arguments!" << endl;
        //return 0;
    }

    string line;
    ifstream myFile("input.txt");
    //ifstream myFile( argv[0] );

    if ( !myFile.is_open() )
    {
        cout << "Unable to open file" << endl;
        return 0;
    }
    else
    {
        getline(myFile, line);
        int size = atoi( line.c_str() ); //get size from first line

        while ( size > 0 && getline(myFile, line) )
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

            tmpTask->show();
            size--;
        } //end of while loop

        myFile.close();
    }


    return 0;
}
