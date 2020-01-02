#ifndef HAN_H_INCLUDED
#define HAN_H_INCLUDED
#include<fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
extern int primary_num;
extern int high_num;
extern int college_num;
extern string check;
class primary;
class high;
class student;
class college;
bool check_(primary *a);
bool check_1(high *a);
bool check_2(college *a);
void rece(string n);
void show(student *a);
#endif // HAN_H_INCLUDED
