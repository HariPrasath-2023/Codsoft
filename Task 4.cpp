#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

// Function prototypes
void addTask(vector<Task>& tasks, const string& description);
void viewTasks(const vector<Task>& tasks);
void markAsCompleted(vector<Task>& tasks, int taskIndex);
void removeTask(vector<Task>& tasks, int taskIndex);

int main() {
    vector<Task> tasks;

    int choice;
    do {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string description;
                cout << "Enter the task description: ";
                cin.ignore(); // To consume the newline character left in the buffer
                getline(cin, description);
                addTask(tasks, description);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                int index;
                cout << "Enter the task index to mark as completed: ";
                cin >> index;
                markAsCompleted(tasks, index);
                break;
            }
            case 4: {
                int index;
                cout << "Enter the task index to remove: ";
                cin >> index;
                removeTask(tasks, index);
                break;
            }
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

void addTask(vector<Task>& tasks, const string& description) {
    Task newTask = {description, false};
    tasks.push_back(newTask);
    cout << "Task added successfully.\n";
}

void viewTasks(const vector<Task>& tasks) {
    cout << "\nTasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". ";
        cout << (tasks[i].completed ? "[✔️] " : "[ ] ");
        cout << tasks[i].description << endl;
    }
}

void markAsCompleted(vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
        tasks[taskIndex - 1].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task index.\n";
    }
}

void removeTask(vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + taskIndex - 1);
        cout << "Task removed successfully.\n";
    } else {
        cout << "Invalid task index.\n";
    }
}