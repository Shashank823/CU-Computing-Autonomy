#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Student {
    string firstName;
    string lastName;
    int studentID;
    double GPA;
};

void printStudents(vector<Student> students) {
    
    int n = students.size();
    for (int i = 0; i < n; i++ ) {
        cout<< "FirstName = "<< students[i].firstName<< "|" << "LastName = "<< students[i].lastName<< "|" << "StudentId = "<<students[i].studentID<< "|" << "GPA ="<<students[i].GPA<< "\n"; 
    }
};

vector<Student> addStudent(vector<Student> students) {

    Student newStudent;

    cout << "First Name: ";
    cin >> newStudent.firstName;
    cout << "Last Name: ";
    cin >> newStudent.lastName;
    cout << "ID: ";
    cin >> newStudent.studentID;
    cout << "GPA: ";
    cin >> newStudent.GPA;
    
    students.push_back(newStudent);

    return students;
}

vector<Student> delStudent(vector<Student> students) {
    int studentIDtoDel;
    cout << "ID of student to delete: ";
    cin >> studentIDtoDel;

    cout << "ID to delete: " << studentIDtoDel << endl;

    vector<Student> newStudents;
    
    int n = students.size();
    
    for (int i = 0; i < n; i++) {
        if (students[i].studentID == studentIDtoDel) {
            continue;
        }
        newStudents.push_back(students[i]);
    }
    
    return newStudents;
}

int main() {
    
    vector<Student> students;
    string input;

    while (true) {
        cout<<"Input operation: ";
        cin >> input;

        if (input == "ADD" || input == "a" || input == "add") {
            students = addStudent(students);
        }
        else if (input == "PRINT" || input == "p" || input == "print") {
            printStudents(students);
        }
        else if (input == "DELETE" || input == "d" || input == "delete") {
            students = delStudent(students);
        }
        else if (input == "QUIT" || input == "q" || input == "quit") {
            return 0;
        }
    }
}
