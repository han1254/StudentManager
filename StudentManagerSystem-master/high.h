#ifndef HIGH_H_INCLUDED
#define HIGH_H_INCLUDED
#include<fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
class high:public student
{
public:

    void set_score();
    void show_info();
    friend void search(high*a,int n);
    friend void delet(high*a,int n);
    friend bool check_1(high *a);
    friend void sort_(high *a);
    friend void sort_1(high *a);
    friend void sort_2(high *a);
    friend void sort_3(high *a);
    friend void sort_4(high *a);
    friend void sort_5(high *a);
    friend bool myCompare2(const high &a1, const high &a2);
    friend bool myCompare2_eng(const high &a1, const high &a2);
    friend bool myCompare2_chi(const high &a1, const high &a2);
    friend bool myCompare2_mat(const high &a1, const high &a2);
    friend bool myCompare2_his(const high &a1, const high &a2);
    friend bool myCompare2_geo(const high &a1, const high &a2);
    friend void statis(high *a);
    friend void edit(high *a,int n);
    friend void high_write(high*a,int n);
    friend void high_read(high*a,int n);
    static high *myPosition1;
    bool set_info();

private:
    double s_english;
    double s_math;
    double s_chinese;
    double s_sum;
    double s_history;
    double s_geog;
} ;


#endif // HIGH_H_INCLUDED
