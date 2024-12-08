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

void loadTasks()
{
    taskfile.open(File_Name, ios::in);
    if (!taskfile)
    {
        cout << "No saved tasks found. Starting fresh." << endl;
        return;
        tasksCount = 0;
        string line;
        while (getline(taskfile, line))
        {
            int position = line.find("|");
            if (position != string::npos)
            {
                Tasks[tasksCount] = line.substr(0, position);
                Condition[tasksCount] = (line.substr(position + 1) == "1");
                tasksCount++;
            }
        }
    }
    taskfile.close();
}
int main()
{
    loadTasks(); // load previous tasks

    int choice;
    do
    {
        cout << "\n======= To-Do list Menu=======" << endl;
        cout << "1. Add a New task" << endl;
        cout << "2. View All Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Delete a Task" << endl;
        cout << "5. Save and Exit" << endl;
        cout << "=====================================" << endl;
        cout << "Please select an option (1-5): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addTasks();
            break;
        case 2:
            view();
            break;
        case 3:
            markComplete();
            break;
        case 4:
            deleteTasks();
            break;
        case 5:
            saveTasks();
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice >= 1 && choice <= 5);

    return 0;
}
