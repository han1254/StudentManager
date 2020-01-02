#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include<fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
using namespace std;
struct INFO
{
    string id;
    string name;
    int age;
    string grade;
    string clas;
    char sex;
    string magor;
};

class student
{
public:

    void set_info();
    virtual void show_info() = 0;

    INFO get_info();
    friend void rece(string n);


protected:
    INFO info;
};



#endif // STUDENT_H_INCLUDED
