/*
Ali Burak ERDOĞAN
21301492
CS202 - Section 3
Homework#3
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <string>
using namespace std;
#include "Task.h"

struct Server {
    int timeLeftToFinish;
    bool busy;

    Server()
    {
        busy = false;
        timeLeftToFinish = 0;
    }
};

class Servers
{
public:
   Servers();
   Servers(int numServers);

   bool isBusy(int id);
   void update();
   void process( Task* task, int currTime);
   int getTotalWaiting();
   string getLog();
   int getNumServers();
   bool allServersBusy();
   bool allServersEmpty();

private:
    int numServers;
    Server *servers;
    string logFile;
    int totalWaiting;
};

#endif
