#ifndef PRIMARY_H_INCLUDED
#define PRIMARY_H_INCLUDED
#include<fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
class primary:public student
{
public:

    void set_score();
    void show_info();
    friend bool check_(primary *a);
    friend void search(primary *a,int n);
    friend void delet(primary*a,int n);
    friend void sort_(primary *a);
    friend void sort_1(primary *a);
    friend void sort_2(primary *a);
    friend void sort_3(primary *a);
    friend bool myCompare1(const primary &a1, const primary &a2);
    friend bool myCompare1_eng(const primary &a1, const primary &a2);
    friend bool myCompare1_chi(const primary &a1, const primary &a2);
    friend bool myCompare1_mat(const primary &a1, const primary &a2);
    friend void statis(primary *a);
    friend void edit(primary *a,int n);
    friend void primary_write(primary*a,int n);
    friend void primary_read(primary*a,int n);
    static primary *myPosition;
    bool set_info();
private:
    double s_english;
    double s_math;
    double s_chinese;
    double s_sum;

};


#endif // PRIMARY_H_INCLUDED
