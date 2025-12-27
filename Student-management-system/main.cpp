#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class representing a Student
class Student {
private:
    int id;                 // Student ID
    int grade;              // Student grade level
    string name;            // Student name
    vector<string> courses; // List of courses the student is enrolled in

public:
    // Constructor
    Student(int id, int grade, string name) {
        this->id = id;
        this->grade = grade;
        this->name = name;
    }

    // Getters
    int Getid() { return id; }
    int Getgrade() { return grade; }
    string getName() { return name; }

    // Add a course to the student
    void addCourse(string c) { courses.push_back(c); }

    // Delete a course from the student
    void deleteCourse(string c) {
        for (int i = 0; i < courses.size(); i++) {
            if (courses[i] == c) {
                courses.erase(courses.begin() + i);
                cout << "Course has been deleted successfully\n";
                return;
            }
        }
        cout << "Course is not found\n";
    }

    // Display student information
    void display() {
        cout << id << "\n " << name << "\n Grade:" << grade << "\nCourses: ";
        if (courses.empty()) {
            cout << "None";
        }
        else {
            for (int i = 0; i < courses.size(); i++)
                cout << courses[i] << " ";
        }
        cout << "\n\n";
    }
};

// Class to manage the student system
class SystemManager {
public:
    vector<Student> students; // List of all students

    // Find index of a student by ID
    int findIndex(int id) {
        for (int i = 0; i < students.size(); i++)
            if (students[i].Getid() == id)
                return i;
        return -1;
    }

    // Add a new student
    void addStudent() {
        int id, grade;
        string name;
        cout << "Add the ID: ";
        cin >> id;
        cout << "Add the name: ";
        cin >> name;
        cout << "Add the grade: ";
        cin >> grade;
        cout << "\nStudent Added Successfully\n";
        students.push_back(Student(id, grade, name));
    }

    // Delete a student
    void deleteStudent() {
        int id;
        cout << "Enter the ID of the student: ";
        cin >> id;
        int index = findIndex(id);
        if (index != -1) {
            students.erase(students.begin() + index);
            cout << "\nStudent deleted Successfully\n";
        }
        else {
            cout << "Student not found\n";
        }
    }

    // Add a course to a specific student
    void addCourseToStudent() {
        int id;
        string c;
        cout << "Enter the ID of the Student: ";
        cin >> id;
        cout << "Enter the Course's Name: ";
        cin >> c;
        int index = findIndex(id);
        if (index != -1) {
            students[index].addCourse(c);
            cout << "Course has been Added Successfully\n";
        }
        else {
            cout << "Student not found\n";
        }
    }

    // Delete a course from a specific student
    void deleteCourseFromStudent() {
        int id;
        string c;
        cout << "Enter the ID of the Student: ";
        cin >> id;
        cout << "Enter the Course's Name: ";
        cin >> c;
        int index = findIndex(id);
        if (index != -1) {
            students[index].deleteCourse(c);
        }
        else {
            cout << "Student not found\n";
        }
    }

    // Display all students and their courses
    void displayAll() {
        if (students.empty()) {
            cout << "No students\n";
        }
        else {
            for (int i = 0; i < students.size(); i++)
                students[i].display();
        }
    }

    // Main menu for user interaction
    void menu() {
        int choice;
        while (true) {
            cout << "\n--- Student Mangement Menu ---\n";
            cout << "1. Add Student\n";
            cout << "2. Delete Student\n";
            cout << "3. Add Course to Student\n";
            cout << "4. Delete Course from student\n";
            cout << "5. Display All Students\n";
            cout << "6. Exit\n\n";
            cout << "Enter Your Choice: ";

            cin >> choice;

            switch (choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: addCourseToStudent(); break;
            case 4: deleteCourseFromStudent(); break;
            case 5: displayAll(); break;
            case 6: cout << "Exiting Now... Thank you for using our system\n\n";
                return;
            }
        }
    }
};

int main() {
    SystemManager sys; // Create system manager instance
    sys.menu();         // Start menu
    return 0;
}
