#include <iostream>
#include <string>
using namespace std;

// Constants
const int MAX_TASKS = 100;

// Global Variables
string tasks[MAX_TASKS];
bool isCompleted[MAX_TASKS];
int taskCount = 0;

// Function to add a task
void addTask()
{
    if (taskCount >= MAX_TASKS)
    {
        cout << "Task list is full!" << endl;
        return;
    }
    cout << "Enter the task description: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, tasks[taskCount]);
    isCompleted[taskCount] = false; // Mark as not completed
    taskCount++;
    cout << "Task added successfully!" << endl;
}

// Function to view all tasks
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

// Main function
int main()
{
    int choice;
    do
    {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addTask();
            break;
        case 2:
            viewTasks();
            break;
        case 3:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}

