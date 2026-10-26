#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Base class demonstrating Abstraction and OOP principles
class User {
protected:
    int id;
    std::string name;
    std::string role;

public:
    User(int userId, std::string userName, std::string userRole) 
        : id(userId), name(userName), role(userRole) {}

    virtual ~User() {}

    virtual void displayInfo() const {
        std::cout << "ID: " << id << " | Name: " << name << " | Role: " << role << "\n";
    }

    std::string getName() const { return name; }
};

// Derived class for Volunteers
class Volunteer : public User {
private:
    std::string skill;

public:
    Volunteer(int userId, std::string userName, std::string userSkill)
        : User(userId, userName, "Volunteer"), skill(userSkill) {}

    void displayInfo() const override {
        std::cout << "[Volunteer] ID: " << id << " | Name: " << name << " | Skill: " << skill << "\n";
    }
};

// Project model structure
struct ServiceProject {
    int projectId;
    std::string title;
    bool isPublished;
};

class ProjectManager {
private:
    std::vector<ServiceProject> projects;

public:
    void addProject(int id, std::string title) {
        projects.push_back({id, title, true});
        std::cout << "Project added successfully!\n";
    }

    void listProjects() const {
        std::cout << "\n--- Active Community Projects ---\n";
        for (const auto& p : projects) {
            std::cout << "Project #" << p.projectId << ": " << p.title 
                      << " [" << (p.isPublished ? "Published" : "Draft") << "]\n";
        }
    }
};

int main() {
    ProjectManager manager;
    std::vector<User*> users;

    // Initializing demo data
    users.push_back(new Volunteer(1, "Isha Chuphal", "Data Entry"));
    users.push_back(new Volunteer(2, "Riya Verma", "Community Outreach"));

    manager.addProject(101, "Clean Water Drive");
    manager.addProject(102, "Youth Education Camp");

    int choice;
    do {
        std::cout << "\n=== Service Record Management System ===\n";
        std::cout << "1. View All Users\n";
        std::cout << "2. View Projects\n";
        std::cout << "3. Add New Project\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            function:
            case 1:
                std::cout << "\n--- Registered Users ---\n";
                for (const auto& u : users) {
                    u->displayInfo();
                }
                break;
            case 2:
                manager.listProjects();
                break;
            case 3: {
                int id;
                std::string title;
                std::cout << "Enter Project ID: ";
                std::cin >> id;
                std::cout << "Enter Project Title: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                manager.addProject(id, title);
                break;
            }
            case 4:
                std::cout << "Exiting program. Good luck with your submissions!\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    // Clean up memory
    for (auto u : users) {
        delete u;
    }

    return 0;
}