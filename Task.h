#ifndef TASK_H_
#define TASK_H_

#include <string>
using namespace std;

//typedef int KeyType;

class Task
{
public:
   Task();
   Task(int priority, int id, int requestTiem, int processTime);

   int getPriority();
   int getId();
   int getRequestTime();
   int getProcessTime();
   void setProcessTime( int processTime );
   void setId( int id );
   void setRequestTime( int requestTime );
   void setPriority( int priority);
   void show();

private:
   int id;
   int priority;
   int requestTime;
   int processTime;
};

#endif
