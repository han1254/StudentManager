#include "student.h"
#include "han.h"
#include "primary.h"
#include "high.h"
#include "college.h"
int primary_num=0;
int high_num=0;
int college_num=0;
string check;
void student::set_info()
{
    string ID;
    string NAME;
    int  AGE;
    string GRADE;
    string CLASS;
    char SEX;
    cout<<"������id��"<<endl;
    cin>>ID;
    rece(ID);
    cout<<"���������֣�"<<endl;
    cin>>NAME;
    cout<<"���������䣺"<<endl;
    cin>>AGE;
    cout<<"�������꼶��"<<endl;
    cin>>GRADE;
    cout<<"������༶��"<<endl;
    cin>>CLASS;
    cout<<"�������Ա�"<<endl;
    cin>>SEX;
    info.id =ID;
    info.name =NAME;
    info.age =AGE;
    info.grade =GRADE;
    info.clas =CLASS;
    info.sex =SEX;
}
INFO student::get_info()
{
    return this->info;
}
