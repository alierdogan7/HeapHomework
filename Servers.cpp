#include <string>
#include <sstream>
using namespace std;

#include "Task.h"
#include "Servers.h"

/*struct Server {
    int timeLeftToFinish;
    bool busy;
}

int numServers;
Server **servers;

*/

string to_string(int number)
{
    stringstream sstm;
    sstm << number;
    return sstm.str();
}

Servers::Servers()
{
    numServers = 0;
    servers = NULL;
    logFile = "";
    totalWaiting = 0;
}

Servers::Servers(int numServers)
{
    this->servers = new Server[numServers];
    this->numServers = numServers;
    this->logFile = string("");
    this->logFile += "Minimum number of computers required: " + to_string(numServers)
                    + "Simulation with " + to_string(numServers) + " computers:\n";
    this->totalWaiting = 0;
}


void Servers::update()
{
    for(int i = 0; i < numServers; i++)
    {
        if( servers[i].busy )
            if(--servers[i].timeLeftToFinish <= 0)
            {
                servers[i].busy = false;
                servers[i].timeLeftToFinish = 0;
            }
    }
}

void Servers::process( Task* task, int currTime )
{
    for(int i = 0; i < numServers; i++)
    {
        if( !servers[i].busy)
        {
            servers[i].timeLeftToFinish = task->getProcessTime();
            servers[i].busy = true;
            logFile += "Computer " + to_string(i) + " takes request "
                    + to_string( task->getId()) + " at ms " + to_string( currTime)
                    + " (wait: " + to_string( currTime - task->getRequestTime() )
                    + " ms)\n";
            totalWaiting += currTime - task->getRequestTime();

            return;
        }
    }
}


bool Servers::isBusy(int id) { return servers[id].busy; }

int Servers::getTotalWaiting() { return totalWaiting; }

string Servers::getLog() { return logFile; }

int Servers::getNumServers() { return numServers; }

bool Servers::allServersBusy()
{
    bool allBusy = true;
    for (int i = 0; i < numServers; i++)
    {
        if( !servers[i].busy )
        {
            allBusy = false;
            break;
        }
    }
    return allBusy;
}
