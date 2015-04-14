#include "Task.h"

Task::Task( int priority, int id, int requestTiem, int processTime )
{
    this->priority = priority;
    this->id = id;
    this->requestTime = requestTime;
    this->processTime = processTime;
}

int Task::getPriority() { return priority; }
int Task::getId() { return id; }
int Task::getRequestTime() { return requestTime; }
int Task::getProcessTime() { return processTime; }
