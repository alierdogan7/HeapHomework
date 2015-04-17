#ifndef SERVER_H_
#define SERVER_H_

#include <string>
using namespace std;
#include "Task.h"

struct Server {
    int timeLeftToFinish;
    bool busy;
}

class Servers
{
public:
   Servers();
   Servers(int numServers);

   bool isBusy(int id);
   void updateTime();
   void process( Task* task);

private:
    int numServers;

};

#endif
