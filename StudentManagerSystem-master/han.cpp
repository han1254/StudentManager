#include "student.h"
#include "han.h"
#include "primary.h"
#include "high.h"
#include "college.h"
void show(student *a)//定义show函数，传入地址，分别对应不同的输出
{
    a->show_info();
}
void rece(string n)
{
    check=n;
}
bool check_(primary *a)
{
    for(int i=0; i<primary_num; i++)
    {
        if(a[i].info.id==check)
        {
            return false;

        }

    }
    return true;
}
bool check_1(high *a)
{
    for(int i=0; i<high_num; i++)
    {
        if(a[i].info.id==check)
        {
            return false;

        }

    }
    return true;
}
bool check_2(college *a)
{
    for(int i=0; i<college_num; i++)
    {
        if(a[i].info.id==check)
        {
            return false;

        }

    }
    return true;
}








