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