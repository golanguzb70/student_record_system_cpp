#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <iomanip>
#include "student.h"

using namespace std;

void add_student(vector<Student>* students) {
    int choice;
    while(true) {
        add_student_menu();
        cout << ">>> ";
        cin >> choice;

        if (choice == 1) {
            // upload using csv
        } else if (choice == 2) {
            // manual adding
            add_student_manually(students);
        } else {
            break;
        }
    }
}

void update_student(vector<Student>* students) {
    string id;
    Student cur;

    int index = -1;
    do {
        cout << "+-----------------------------------------------+" << endl;
        cout << "|             Enter id of student               |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cout << ">>> ";

        cin >> id;
        for (int i = 0; i < students->size(); i++) {
            if (students->at(i).id == id) {
                index = i;
                break;
            }
        }
        if (index < 0) {
            cout << "Enter 0 if you want to stop searching >>> ";
            cin >> index;
            if (index == 0) {
                return;
            } else {
                index = -1;
            }
        }
    } while(index < 0);
    
    cur = students->at(index);
    display_student(&cur);
    students->at(index).id = "";
    cur = create_student(students);
    students->at(index) = cur;  
}

void add_student_manually(vector<Student>* students) {
    Student student = create_student(students);
    students->push_back(student);
}

Student create_student(vector<Student>* students) {
    Student student;
    cout << "Name: ";
    cin >> student.name;

    do {
        cout << "Student Id: ";
        cin >> student.id;
    } while(!is_valid_id(students, student.id));

    do {
        cout << "Grade: ";
        cin >> student.grades;
    } while(!is_valid_grade(student.grades));  

    return student;
}

bool is_valid_grade(int grade) {
    bool response = (grade >= 0 & grade <= 100);
    if (!response) {
        cout << "!!! Grade should be in range of 0 and 100: [0, 100] !!!" << endl;
    }
    return response;
}

bool is_valid_id(vector<Student>* students, string id) {
    bool response = true;
    regex pattern("^[1-9]{6}$");

    response = regex_match(id, pattern);
    if (!response) {
        cout << "!!! Student id should be 6-digit string consisting of numbers 1 to 9 !!!" << endl;
        return response;
    }
    
    // check for uniqueness
    for (int i = 0; i < students->size(); i++) {
        if (students->at(i).id == id) {
            response = false;
            break;
        } 
    }
    if (!response) {
        cout << "!!! Student id should be unique, this id has already been used !!!" << endl;
    }

    return response;
}

void display_student(Student* student) {
    cout << "+----------+-----------------------+------------+" << endl;
    cout << "|    Id    |         Name          |    Grade   |" << endl;
    cout << "+----------+-----------------------+------------+" << endl;
    cout << "|  " << left << setw(6) << student->id << "  |  " << left << setw(19) << student->name << "  |  " << left << setw(8) << student->grades <<  "  |" << endl;
    cout << "+-----------------------------------------------+" << endl;
}

void main_menu() {
    cout << "+-----------------------------------------------+" << endl;
    cout << "|       1. Add Student                          |" << endl;
    cout << "|       2. Update Student                       |" << endl;
    cout << "|       3. Delete Student                       |" << endl;
    cout << "|       4. Display Student                      |" << endl;
    cout << "|       5. Export to excel                      |" << endl;
    cout << "|       6. Exit                                 |" << endl;
    cout << "+-----------------------------------------------+" << endl;
}

void add_student_menu() {
    cout << "+-----------------------------------------------+" << endl;
    cout << "|       1. Upload using CSV                     |" << endl;
    cout << "|       2. Add manually                         |" << endl;
    cout << "|       3. Exit                                 |" << endl;
    cout << "+-----------------------------------------------+" << endl;
}