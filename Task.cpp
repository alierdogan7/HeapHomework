#include <iostream>
using namespace std;

#include "Task.h"

Task::Task()
{
}

Task::Task( int priority, int id, int requestTiem, int processTime )
{
    this->priority = priority;
    this->id = id;
    this->requestTime = requestTime;
    this->processTime = processTime;
}

void Task::show()
{
    cout << "ID: " << id << ", Priority: " << priority
         << ", Request Time: " << requestTime << ", Process Time: " << processTime << endl;
}

int Task::getPriority() { return priority; }
int Task::getId() { return id; }
int Task::getRequestTime() { return requestTime; }
int Task::getProcessTime() { return processTime; }

void Task::setPriority( int priority ) { this->priority = priority; }
void Task::setId( int id ) { this->id = id; }
void Task::setRequestTime( int requestTime ) { this->requestTime = requestTime; }
void Task::setProcessTime( int processTime ) { this->processTime = processTime; }
