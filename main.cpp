#include <iostream>
#include <string>
using namespace std;

const int MAX_TASKS = 100;

string tasks[MAX_TASKS];
bool isCompleted[MAX_TASKS];
int taskCount = 0;


void addTask()
{
    if (taskCount >= MAX_TASKS)
    {
        cout << "Task list is full!" << endl;
        return;
    }
    cout << "Enter the task description: ";
    cin.ignore(); 
    getline(cin, tasks[taskCount]);
    isCompleted[taskCount] = false; 
    taskCount++;
    cout << "Task added successfully!" << endl;
}

void viewTasks()
{
    if (taskCount == 0)
    {
        cout << "No tasks available." << endl;
        return;
    }
    cout << "Your Tasks:" << endl;
    for (int i = 0; i < taskCount; i++)
    {
        cout << i + 1 << ". [" << (isCompleted[i] ? "X" : " ") << "] " << tasks[i] << endl;
    }
}
int main()
{
}

  
