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
void deleteTasks();
void loadTasks();
void saveTasks();
void view();
void markComplete();

int main()
{
   loadTasks(); //load previous tasks

    int choice;
    do {
    cout <<"\n======= To-Do list Menu=======" <<endl;
    cout <<"1. Add a New task"<< endl;
    cout << "2. View All Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Delete a Task" << endl;
    cout << "5. Save and Exit" << endl;
    cout << "=====================================" << endl;
    cout << "Please select an option (1-5): ";
    cin >> choice;


   switch (choice) {
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
    } while (choice>=1 && choice<=5 );

    return 0;
}

