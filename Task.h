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

private:
   int id;
   int priority;
   int requestTime;
   int processTime;
}; // end KeyedItem
