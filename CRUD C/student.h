#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

struct Student
{
    string name;
    float grade1;
    float grade2;
};

Student inputStudent();
void addStudent();
void searchStudent();
void updateStudent();
void deleteStudent();

#endif