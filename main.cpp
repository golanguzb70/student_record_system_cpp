#include <iostream>
#include "student.h"
#include <vector>
#include <string>
using namespace std;


/*
Student Record System

Objective: To create a C++ program that manages student records.

Requirements:
• The program should use structs to define a Student with attributes such as name, ID, and grades.
• Implement a vector to store multiple student records.
• Provide options for adding, updating, deleting, and displaying student records.
• Use appropriate control flow statements for menu-driven user interaction.
• The program should ensure data validation (e.g., valid grade ranges).

Implement a function to calculate and display the average grade of all students.
• Ensure that the program allows users to save and load student records to/from a file.
• Use appropriate error handling for file operations and user input.
*/

int main() {
    int choice;
    vector <Student> students;

    while(true) {
        main_menu();

        cout << "Enter choice >>> ";
        cin >> choice;

        if (choice == 6) {
            cout << "Thank you" << endl;
            break;
        }

        switch (choice)
        {
        case 1:
            add_student(&students);
            break;
        case 2:
            update_student(&students);
            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }

        if (choice < 1 || choice > 6) {
            break;
        }
    }   
}
