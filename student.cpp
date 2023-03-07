#include <iostream>
#include <string>
using namespace std;

// Define a student class
class Student {
    private:
        string name;
        int age;
        int id;
        float grade;
    public:
        void setStudent(string n, int a, int i, float g) {
            name = n;
            age = a;
            id = i;
            grade = g;
        }
        void displayStudent() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "ID: " << id << endl;
            cout << "Grade: " << grade << endl;
        }
        int getID() {
            return id;
        }
};

// Define a global array of student records
const int MAX_STUDENTS = 100;
Student students[MAX_STUDENTS];
int numStudents = 0;

// Function to add a new student record
void addStudent() {
    string name;
    int age;
    int id;
    float grade;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter grade: ";
    cin >> grade;
    Student s;
    s.setStudent(name, age, id, grade);
    students[numStudents] = s;
    numStudents++;
    cout << "Student record added successfully." << endl;
}

// Function to display all student records
void displayAllStudents() {
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << i+1 << ":" << endl;
        students[i].displayStudent();
    }
}

// Function to search for a student record by ID
void searchStudentByID() {
    int id;
    cout << "Enter ID: ";
    cin >> id;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].getID() == id) {
            cout << "Student found:" << endl;
            students[i].displayStudent();
            return;
        }
    }
    cout << "Student not found." << endl;
}

// Main function
int main() {
    int choice;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add student record" << endl;
        cout << "2. Display all student records" << endl;
        cout << "3. Search student record by ID" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllStudents();
                break;
            case 3:
                searchStudentByID();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
