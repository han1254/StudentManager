#ifndef COLLEGE_H_INCLUDED
#define COLLEGE_H_INCLUDED
#include<fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
class college:public student
{
public:
    void set_score();
    void show_info();
    friend void search(college*a,int n);
    friend void delet(college *a,int n);
    friend bool check_2(college *a);
    friend void sort_(college *a);
    friend void sort_1(college *a);
    friend void sort_2(college *a);
    friend void sort_3(college *a);
    friend void sort_4(college *a);

    friend bool myCompare3(const college &a1, const college &a2);
    friend bool myCompare3_eng(const college &a1, const college &a2);
    friend bool myCompare3_chi(const college &a1, const college &a2);
    friend bool myCompare3_mat(const college &a1, const college &a2);
    friend bool myCompare3_magor(const college &a1, const college &a2);
    friend bool myCompare3_c(const college &a1, const college &a2);
    friend void statis(college *a);
    friend void edit(college *a,int n);
    friend void college_write(college*a,int n);
    friend void college_read(college*a,int n);
    static college *myPosition2;
    bool set_info();

private:
    double s_english;
    double s_math;
    double s_magor;
    double s_c;
    double s_sum;

} ;

#endif // COLLEGE_H_INCLUDED
