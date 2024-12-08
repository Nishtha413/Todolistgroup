#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int maxtasks = 100;

string Tasks[maxtasks];
bool Condition[maxtasks];
int tasksCount = 0;

const string File_Name = "tasks.txt";

void addTasks();
void deleteTasks()
{
    view();
    if (tasksCount == 0)
        return;
    cout << "Enter the task number to delete: ";
    int taskNumber;
    cin >> taskNumber;
    if (taskNumber < 1 || taskNumber > tasksCount)
    {
        cout << "Invalid task number!" << endl;
    }
    for (int i = taskNumber - 1; i < tasksCount - 1; i++)
    {
        Tasks[i] = Tasks[i + 1];
        Condition[i] = Condition[i + 1];
    }
    tasksCount--;
    cout << "Task deleted successfully!" << endl;
};

void loadTasks();
void saveTasks();
void view();
void markComplete()
{
    view();
    if (tasksCount == 0)
        return;
    cout << "Enter the task number to mark as completed: ";
    int taskNumber;
    cin >> taskNumber;
    if (taskNumber < 1 || taskNumber > tasksCount)
    {
        cout << "Invalid task number!" << endl;
        return;
    }
    Condition[taskNumber - 1] = true;
    cout << "Task marked as completed!" << endl;
};

int main()
{
}