#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int maxtasks = 100;

string Tasks[maxtasks];
bool Condition[maxtasks];
int tasksCount = 0;

const string File_Name = "tasks.txt";

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
void deleteTasks();
void loadTasks();
void saveTasks();

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
void markComplete();

int main()
{
}
  
