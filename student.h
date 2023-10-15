#include <string>
#include <vector>
#ifndef STUDENT_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define STUDENT_H

using namespace std;


struct Student {
    string id;
    string name;
    int grades;
};

// Menu
void main_menu();
void add_student_menu();

// Student operations
void add_student(vector<Student>* students);
void update_student(vector<Student>* students);
void delete_student(vector<Student>* students);
void display_student(Student* student);

// validation
bool is_valid_grade(int grade);
bool is_valid_id(vector<Student>* students, string id);

// helper
void add_student_manually(vector<Student>* students);
Student create_student(vector<Student>* students);
#endif