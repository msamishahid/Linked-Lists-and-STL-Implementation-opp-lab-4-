#include <iostream>
#include <list>
#include <string>
using namespace std;
class TodoList {
private:
    string task;
    list<TodoList> subTasks;

public:
    TodoList(const string& task) : task(task) {}
    void addSubTask(const string& subTask) {  // Function to add a sub-task
        subTasks.emplace_back(subTask);
    }
    // Function to display the task and its sub-tasks recursively
    void display(int depth = 0) const {
        for (int i = 0; i < depth; ++i)
            cout << "  ";                 
        cout << "- " << task << endl;
        for (const auto& subTask : subTasks)
            subTask.display(depth + 1); 
    }
    list<TodoList>& getSubTasks() {    
        return subTasks;
    }
};
int main() {
    TodoList todoList("Main Task");
    todoList.addSubTask("Subtask 1");
    todoList.addSubTask("Subtask 2");

    todoList.getSubTasks().front().addSubTask("Subtask 1.1"); // Adding sub-tasks to Subtask 1
    todoList.getSubTasks().front().addSubTask("Subtask 1.2");    
    todoList.getSubTasks().back().addSubTask("Subtask 2.1");  // Adding sub-tasks to Subtask 2

    cout << "To-Do List:" << endl;
    todoList.display();
    return 0;
}
