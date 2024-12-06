#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int maxtasks = 100;

string Tasks[maxtasks];
bool Condition[maxtasks];
int tasksCount = 0;

const string File_Name = "tasks.txt";
fstream taskfile;

void addTasks();
void deleteTasks();
void loadTasks();
void saveTasks();
void view();
void markComplete();

void saveTasks()
{

    taskfile.open(File_Name, ios ::app);
    if (taskfile.is_open())
    {
        for (int i = 0; i < tasksCount; i++)
        {
            taskfile << Tasks[i] << "|" << (Condition[i] ? "1" : "0") << endl;
        }
        taskfile.close();
    }
}
int main()
{
}