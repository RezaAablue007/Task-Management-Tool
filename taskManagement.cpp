#include <iostream>
#include <vector>
#include <string>

// Define a Task struct to store task information
struct Task {
    std::string description;
    bool isComplete;

    Task(const std::string& desc) : description(desc), isComplete(false) {}
};

// Function to add a task to the task list
void addTask(std::vector<Task>& taskList, const std::string& description) {
    Task newTask(description);
    taskList.push_back(newTask);
    std::cout << "Task added: " << description << std::endl;
}

// Function to mark a task as complete
void markComplete(std::vector<Task>& taskList, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < taskList.size()) {
        taskList[taskIndex].isComplete = true;
        std::cout << "Task marked as complete: " << taskList[taskIndex].description << std::endl;
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

// Function to list all tasks
void listTasks(const std::vector<Task>& taskList) {
    std::cout << "Task List:" << std::endl;
    for (size_t i = 0; i < taskList.size(); ++i) {
        std::cout << "[" << (taskList[i].isComplete ? "X" : " ") << "] " << i + 1 << ". " << taskList[i].description << std::endl;
    }
}

// Function to remove a task from the list
void removeTask(std::vector<Task>& taskList, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < taskList.size()) {
        std::cout << "Removed task: " << taskList[taskIndex].description << std::endl;
        taskList.erase(taskList.begin() + taskIndex);
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

int main() {
    std::vector<Task> taskList;

    while (true) {
        std::cout << "\nTask Management Application\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Mark Task as Complete\n";
        std::cout << "3. List Tasks\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                {
                    std::cin.ignore(); // Clear the newline character from the input buffer
                    std::cout << "Enter task description: ";
                    std::string description;
                    std::getline(std::cin, description);
                    addTask(taskList, description);
                }
                break;

            case 2:
                {
                    std::cout << "Enter the task index to mark as complete: ";
                    int taskIndex;
                    std::cin >> taskIndex;
                    markComplete(taskList, taskIndex - 1);
                }
                break;

            case 3:
                listTasks(taskList);
                break;

            case 4:
                {
                    std::cout << "Enter the task index to remove: ";
                    int taskIndex;
                    std::cin >> taskIndex;
                    removeTask(taskList, taskIndex - 1);
                }
                break;

            case 5:
                std::cout << "Exiting the program.\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
