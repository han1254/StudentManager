#include "student.h"
#include "han.h"
#include "primary.h"
#include "high.h"
#include "college.h"
college* college::myPosition2= NULL;
bool college::set_info()
{
    string ID;
    string NAME;
    int  AGE;
    string GRADE;
    string CLASS;
    char SEX;
    cout<<"请输入id："<<endl;
    cin>>ID;
    rece(ID);
    if (!check_2(college::myPosition2))
    {
        cout << "重复，按回车以重新输入..." << endl;
        getchar();
        getchar();
        return false;
    }
    cout<<"请输入名字："<<endl;
    cin>>NAME;
    cout<<"请输入年龄："<<endl;
    cin>>AGE;
    cout<<"请输入年级："<<endl;
    cin>>GRADE;
    cout<<"请输入班级："<<endl;
    cin>>CLASS;
    cout<<"请输入性别："<<endl;
    cin>>SEX;
    info.id =ID;
    info.name =NAME;
    info.age =AGE;
    info.grade =GRADE;
    info.clas =CLASS;
    info.sex =SEX;
    return true;
}
void college::set_score()
{
    double a,b,c,d,e;
    cout<<"请输入 英语，高数，专业，程序设计 的成绩："<<endl;
    cin>>a>>b>>c>>d;
    s_english = a;
    s_math = b;
    s_magor = c;
    s_c=d;
    s_sum=s_english+s_math+s_magor+s_c;
}
void college::show_info()
{
    INFO t;
    t = get_info();
    cout<<setw(10)<<get_info().name <<setw(8)<<get_info().sex<<setw(12)<<get_info().id<<setw(11)<<get_info().grade <<setw(10)<<get_info().clas<<setw(10)<<this->s_english <<setw(10)
        <<this->s_math<<setw(10)<<this->s_magor <<setw(10)<<s_c<<setw(12)<<this->s_sum<<endl;
    printf(" ──────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
}
void college_read(college*a,int n)
{
    ifstream infile1("college.dat");

    if(!infile1.is_open())
    {
        cout<<"大学生文件打开失败！"<<endl;
        exit(1);
    }
    else
    {

        while(1)
        {
            infile1>>a[college_num].info.id;
            infile1>>a[college_num].info.name;
            infile1>>a[college_num].info.sex;
            infile1>>a[college_num].info.age;
            infile1>>a[college_num].info.grade;
            infile1>>a[college_num].info.clas;
            infile1>>a[college_num].s_english;
            infile1>>a[college_num].s_math;
            infile1>>a[college_num].s_magor;
            infile1>>a[college_num].s_c;
            infile1>>a[college_num].s_sum;
            college_num++;
            if(!infile1)
            {
                college_num--;
                break;
            }
        }

    }
    infile1.close();
}
void college_write(college*a,int n)
{
    ofstream outfile1("college.dat", ios::trunc);
    if(!outfile1)
    {
        cout<<"打开大学生文件失败！"<<endl;
        system("pause");
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            outfile1<<a[i].info.id<<" ";
            outfile1<<a[i].info.name<<" ";
            outfile1<<a[i].info.sex<<" ";
            outfile1<<a[i].info.age<<" ";
            outfile1<<a[i].info.grade<<" ";
            outfile1<<a[i].info.clas<<" ";
            outfile1<<a[i].s_english<<" ";
            outfile1<<a[i].s_math<<" ";
            outfile1<<a[i].s_magor<<" ";
            outfile1<<a[i].s_c<<" ";
            outfile1<<a[i].s_sum<<" "<<endl;
        }
    }
    outfile1.close();
}
void search(college* a, int n)
{
    bool find = false;
    char t1;
    string str;
    cout<<"选择查询方式："<<endl;
    printf("          ┌—————————————┐\n") ;
    printf("          ║ 按名字（1）  按学号（2） ║\n");
    printf("          └—————————————┘\n") ;
    cin>>t1;
    if(t1=='1')
    {
        cout<<"请输入名字：" <<endl;
        cin>>str;
        for(int i=0; i < n; i++)
        {
            if(str == a[i].get_info().name)
            {
                printf(" ──────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

                cout<<setw(10)<<"| 姓名 |"<<setw(10)<<"| 性别 |"<<setw(10)<<"|     学号   |"<<setw(10)<<"| 年级 |" <<setw(10)<<"| 班级 |"<<setw(10)<<"| 英语 |" <<setw(10)<<"| 高数 |"<<setw(10)<<"| 专业 |" <<setw(10)<<"| 程序设计 |"<<setw(10)<<"| 总分 |"<<endl;
                printf("└──────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");


                student* t = &a[i];
                show(t);
                find = true;
            }
        }
    }
    else if(t1=='2')
    {
        cout<<"请输入学号："<<endl;
        cin>>str;
        for(int i=0; i < n; i++)
        {
            if(str == a[i].get_info().id)
            {
                printf(" ──────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

                cout<<setw(10)<<"| 姓名 |" <<setw(10)<<"|     学号   |"<<setw(10)<<"| 年级 |" <<setw(10)<<"| 班级 |"<<setw(10)<<"| 英语 |" <<setw(10)<<"| 高数 |"<<setw(10)<<"| 专业 |" <<setw(10)<<"| 程序设计 |"<<setw(10)<<"| 总分 |"<<endl;
                printf("└──────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");


                student* t = &a[i];
                show(t);
                find = true;
            }
        }
    }


    if (!find)
    {
        cout << "查无此人！" << endl;
    }

}

void delet(college *a,int n)
{
    string t;
    bool flag=false;
    cout<<"输入你想删除的学生学号："<<endl;
    cin>>t;
    int f=0;
    for(int i=0; i<n; i++)
    {
        if(a[i].get_info().id==t)
        {
            flag=true;
            for(int j=i; j<n-1; j++)
            {
                a[j]=a[j+1];
            }
            college_num--;
        }
    }
    if(!flag)
    {
        cout<<"查无此人！"<<endl;
    }

}
bool  myCompare3(const college &a1,const college &a2)//自定义排序
{
    return a1.s_sum>=a2.s_sum;//从小到大排序
}
bool myCompare3_eng(const college &a1, const college &a2)
{
    return a1.s_english>=a2.s_english;
}
bool myCompare3_magor(const college &a1, const college &a2)
{
    return a1.s_magor>=a2.s_magor;
}
bool myCompare3_mat(const college &a1, const college &a2)
{
    return a1.s_math>=a2.s_math;
}
bool myCompare3_c(const college &a1, const college &a2)
{
    return a1.s_c>=a2.s_c;
}
void sort_(college *a)
{
    vector <college> va;
    for(int i=0; i<college_num; i++)
    {
        va.push_back(a[i]);
    }
    sort(va.begin(),va.end(),myCompare3);


    for (int i = 0; i < college_num; i++)
    {
        a[i] = va[i];
    }

    cout<<"这是成绩排名（按总成绩）："<<endl;
    printf(" ──────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

    cout<<setw(10)<<"| 姓名 |" <<setw(10)<<"|     学号   |"<<setw(10)<<"| 年级 |" <<setw(10)<<"| 班级 |"<<setw(10)<<"| 英语 |" <<setw(10)<<"| 高数 |"<<setw(10)<<"| 专业 |" <<setw(10)<<"| 程序设计 |"<<setw(10)<<"| 总分 |"<<setw(10)<<"| 名次 |"<<endl;
    printf("└──────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
    for(int i=0; i<college_num; i++)
    {

        cout<<setw(10)<<a[i].info.name <<setw(11)<<a[i].info.id<<setw(10)<<a[i].info.grade <<setw(10)<<a[i].info.clas<<setw(10)<<a[i].s_english <<setw(10)
            <<a[i].s_math<<setw(10)<<a[i].s_magor <<setw(10)<<a[i].s_c<<setw(12)<<a[i].s_sum<<setw(10)<<i+1<<endl;
        printf(" ──────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
    }
}
void sort_1(college *a)
{
    vector <college> va;
    for(int i=0; i<college_num; i++)
    {
        va.push_back(a[i]);
    }
    sort(va.begin(),va.end(),myCompare3_eng);


    for (int i = 0; i < college_num; i++)
    {
        a[i] = va[i];
    }

    cout<<"这是成绩排名（按英语成绩）："<<endl;
    printf(" ──────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

    cout<<setw(10)<<"| 姓名 |" <<setw(10)<<"|     学号   |"<<setw(10)<<"| 年级 |" <<setw(10)<<"| 班级 |"<<setw(10)<<"| 英语 |" <<setw(10)<<"| 名次 |"<<endl;
    printf("└──────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
    for(int i=0; i<college_num; i++)
    {

        cout<<setw(10)<<a[i].info.name <<setw(11)<<a[i].info.id<<setw(10)<<a[i].info.grade <<setw(10)<<a[i].info.clas<<setw(10)<<a[i].s_english <<setw(10)<<i+1<<endl;
        printf(" ──────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
    }
}
void sort_2(college *a)
{
    vector <college> va;
    for(int i=0; i<college_num; i++)
    {
        va.push_back(a[i]);
    }
    sort(va.begin(),va.end(),myCompare3_mat);


    for (int i = 0; i < college_num; i++)
    {
        a[i] = va[i];
    }

    cout<<"这是成绩排名（按高数成绩）："<<endl;
    printf(" ──────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

    cout<<setw(10)<<"| 姓名 |" <<setw(10)<<"|     学号   |"<<setw(10)<<"| 年级 |" <<setw(10)<<"| 班级 |"<<setw(10)<<"| 高数 |" <<setw(10)<<"| 名次 |"<<endl;
    printf("└──────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
    for(int i=0; i<college_num; i++)
    {

        cout<<setw(10)<<a[i].info.name <<setw(11)<<a[i].info.id<<setw(10)<<a[i].info.grade <<setw(10)<<a[i].info.clas<<setw(10)<<a[i].s_math <<setw(10)<<i+1<<endl;
        printf(" ──────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
    }
}
void sort_3(college *a)
{
    vector <college> va;
    for(int i=0; i<college_num; i++)
    {
        va.push_back(a[i]);
    }
    sort(va.begin(),va.end(),myCompare3_magor);


    for (int i = 0; i < college_num; i++)
    {
        a[i] = va[i];
    }

    cout<<"这是成绩排名（按专业成绩）："<<endl;
    printf(" ──────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

    cout<<setw(10)<<"| 姓名 |" <<setw(10)<<"|     学号   |"<<setw(10)<<"| 年级 |" <<setw(10)<<"| 班级 |"<<setw(10)<<"| 专业 |" <<setw(10)<<"| 名次 |"<<endl;
    printf("└──────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
    for(int i=0; i<college_num; i++)
    {

        cout<<setw(10)<<a[i].info.name <<setw(11)<<a[i].info.id<<setw(10)<<a[i].info.grade <<setw(10)<<a[i].info.clas<<setw(10)<<a[i].s_magor <<setw(10)<<i+1<<endl;
        printf(" ──────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
    }
}
void sort_4(college *a)
{
    vector <college> va;
    for(int i=0; i<college_num; i++)
    {
        va.push_back(a[i]);
    }
    sort(va.begin(),va.end(),myCompare3_c);


    for (int i = 0; i < college_num; i++)
    {
        a[i] = va[i];
    }

    cout<<"这是成绩排名（按程序设计成绩）："<<endl;
    printf(" ──────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

    cout<<setw(10)<<"| 姓名 |" <<setw(10)<<"|     学号   |"<<setw(10)<<"| 年级 |" <<setw(10)<<"| 班级 |"<<setw(10)<<"| 程序设计 |" <<setw(10)<<"| 名次 |"<<endl;
    printf("└──────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
    for(int i=0; i<college_num; i++)
    {

        cout<<setw(10)<<a[i].info.name <<setw(11)<<a[i].info.id<<setw(10)<<a[i].info.grade <<setw(10)<<a[i].info.clas<<setw(10)<<a[i].s_c <<setw(10)<<i+1<<endl;
        printf(" ──────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
    }
}
void  statis(college *a)
{
    char t1;
    char t2;
    char t3;
    cout<<"请选择统计方式"<<endl;
    printf("          ┌———————————————————————————┐\n") ;
    printf("          ║ 查看总人数（1） 查看成绩分布（2） 查看平均成绩（3）  ║\n");
    printf("          └———————————————————————————┘\n") ;
    cin>>t1;
    if(t1=='1')
    {
        cout<<"目前该年级总人数为："<<college_num<<"人"<<endl;
    }
    else if(t1=='2')
    {
        cout<<"您想查看哪一科的成绩分布："<<endl;
        printf("          ┌——————————————————————————————————┐\n") ;
        printf("          ║ 英语（1）     高数（2）   专业（3）    程序设计（4）  总成绩（5）  ║\n");
        printf("          └——————————————————————————————————┘\n") ;
        cin>>t2;
        if(t2=='1')
        {
            int eng1=0;
            int eng2=0;
            int eng3=0;
            for(int i=0; i<college_num; i++)
            {
                if(a[i].s_english<60)
                {
                    eng1++;
                }
                else if(a[i].s_english>=60&&a[i].s_english<=80)
                {
                    eng2++;
                }
                else
                {
                    eng3++;
                }
            }
            printf("          ┌—————————————————┐\n") ;
            printf("          ║  小于60分     60~80    80~100    ║\n");
            printf("          └—————————————————┘\n") ;
            printf("                 %d          %d        %d\n",eng1,eng2,eng3);
        }
        else if(t2=='3')
        {
            int chi1=0;
            int chi2=0;
            int chi3=0;
            for(int i=0; i<college_num; i++)
            {
                if(a[i].s_magor<60)
                {
                    chi1++;
                }
                else if(a[i].s_magor>=60&&a[i].s_magor<=80)
                {
                    chi2++;
                }
                else
                {
                    chi3++;
                }
            }
            printf("          ┌—————————————————┐\n");
            printf("          ║  小于60分     60~80    80~100    ║\n");
            printf("          └—————————————————┘\n");
            printf("                 %d          %d        %d\n",chi1,chi2,chi3);
        }
        else if(t2=='2')
        {
            int mat1=0;
            int mat2=0;
            int mat3=0;
            for(int i=0; i<college_num; i++)
            {
                if(a[i].s_math<60)
                {
                    mat1++;
                }
                else if(a[i].s_math>=60&&a[i].s_math<=80)
                {
                    mat2++;
                }
                else
                {
                    mat3++;
                }
            }
            printf("          ┌—————————————————┐\n") ;
            printf("          ║  小于60分     60~80    80~100    ║\n");
            printf("          └—————————————————┘\n") ;
            printf("                 %d          %d        %d\n",mat1,mat2,mat3);
        }
        else if(t2=='4')
        {
            int c1=0;
            int c2=0;
            int c3=0;
            for(int i=0; i<college_num; i++)
            {
                if(a[i].s_c<60)
                {
                    c1++;
                }
                else if(a[i].s_c>=60&&a[i].s_c<=80)
                {
                    c2++;
                }
                else
                {
                    c3++;
                }
            }
            printf("          ┌—————————————————┐\n") ;
            printf("          ║  小于60分     60~80    80~100    ║\n");
            printf("          └—————————————————┘\n") ;
            printf("                 %d          %d        %d\n",c1,c2,c3);
        }
        else if(t2=='5')
        {
            int sum1=0;
            int sum2=0;
            int sum3=0;
            for(int i=0; i<college_num; i++)
            {
                if(a[i].s_sum<240)
                {
                    sum1++;
                }
                else if(a[i].s_sum>=240&&a[i].s_sum<=320)
                {
                    sum2++;
                }
                else
                {
                    sum3++;
                }
            }
            printf("          ┌—————————————————┐\n");
            printf("          ║  小于240分   240~320   320~400   ║\n");
            printf("          └—————————————————┘\n");
            printf("                 %d          %d        %d\n",sum1,sum2,sum3);
        }

    }
    else if(t1=='3')
    {
        cout<<"您想查看平均成绩的方式："<<endl;
        printf("          ┌——————————————————————————————————┐\n") ;
        printf("          ║ 英语（1）     高数（2）   专业（3）    程序设计（4）  总成绩（5）  ║\n");
        printf("          └——————————————————————————————————┘\n") ;
        cin>>t2;
        if(t2=='1')
        {
            double ave;
            int s=0;
            for(int i=0; i<college_num; i++)
            {
                s+=a[i].s_english;
            }
            ave=s/college_num;
            printf("英语成绩为：%.1lf\n",ave);
        }
        else if(t2=='2')
        {
            double ave;
            double s=0.0;
            for(int i=0; i<college_num; i++)
            {
                s+=a[i].s_magor;
            }
            ave=s/college_num;
            /*cout<<"语文平均成绩为："<<s<<endl; */
            printf("专业平均成绩：%.1lf\n",ave);
        }
        else if(t2=='2')
        {
            double ave;
            double s=0.0;
            for(int i=0; i<college_num; i++)
            {
                s+=a[i].s_math;
            }
            ave=s/college_num;
            /*cout<<"语文平均成绩为："<<s<<endl; */
            printf("高数平均成绩：%.1lf\n",ave);
        }
        else if(t2=='4')
        {
            double ave;
            double s=0.0;
            for(int i=0; i<college_num; i++)
            {
                s+=a[i].s_c;
            }
            ave=s/college_num;
            /*cout<<"语文平均成绩为："<<s<<endl; */
            printf("程序设计平均成绩：%.1lf\n",ave);
        }
        else if(t2=='4')
        {
            double ave;
            double s=0.0;
            for(int i=0; i<college_num; i++)
            {
                s+=a[i].s_sum;
            }
            ave=s/college_num;
            /*cout<<"语文平均成绩为："<<s<<endl; */
            printf("总平均成绩：%.1lf\n",ave);
        }
    }

}
void edit(college *a,int n)
{

    bool flag=false;

    string str;

    cout<<"输入您要更改的学生的学号："<<endl;
    cin>>str;
    for(int i=0; i<n; i++)
    {
        if(a[i].get_info().id==str)
        {
            flag=true;
            cout<<"请选择您要更改的项目："<<endl;
            cout<<"(1)学号 （2）姓名 （3）成绩 （4）性别 (5)年级 （6）班级"<<endl;
            char t1;
            cin>>t1;
            if(t1=='1')
            {
                string c;
                char d;
                cin>>c;
                a[i].info.id=c;
                cout<<"学号修改成功！"<<endl;
            }
            else if(t1=='2')
            {
                string c;
                cin>>c;
                a[i].info.name=c;
            }
            else if(t1=='3')
            {
                cout<<"选择你要修改的成绩：（1）英语 （2）高数  （3）专业 （4）程序设计 （5）我全要改"<<endl;

                char t2;
                cin>>t2;
                if(t2=='1')
                {
                    cout<<"输入修改后的成绩："<<endl;
                    int eng;
                    cin>>eng;
                    a[i].s_english=eng;
                    cout<<"英语成绩修改成功！"<<endl;
                }
                else if(t2=='2')
                {
                    cout<<"输出修改后的成绩："<<endl;
                    int chi;
                    cin>>chi;
                    a[i].s_math=chi;
                    cout<<"高数成绩修改成功！"<<endl;
                }
                else if(t2=='3')
                {
                    cout<<"输入修改后的成绩：" <<endl;
                    int mat;
                    cin>>mat;
                    a[i].s_magor=mat;
                    cout<<"专业成绩修改成功！"<<endl;
                }
                else if(t2=='4')
                {
                    cout<<"输入修改后的成绩：" <<endl;
                    int his;
                    cin>>his;
                    a[i].s_c=his;
                    cout<<"程序设计成绩修改成功！"<<endl;
                }

                else if(t2=='5')
                {
                    cout<<"输入英语，高数，专业，程序设计成绩：" <<endl;
                    int eng,mat,magor,c;
                    cin>>eng>>mat>>magor>>c;
                    a[i].s_english=eng;
                    a[i].s_math=mat;
                    a[i].s_magor=magor;
                    a[i].s_c=c;
                    a[i].s_sum =eng+mat+magor+c;
                    cout<<"成绩修改成功！"<<endl;
                }

            }
            else if(t1=='4')
            {
                char t;
                cout<<"更改性别：" <<endl;
                cin>>t;
                a[i].info.sex=t;
                cout<<"性别修改成功！"<<endl;
            }
            else if(t1=='5')
            {
                char t;
                cout<<"更改年级：" <<endl;
                cin>>t;
                a[i].info.grade=t;
                cout<<"年级修改成功！"<<endl;
            }
            else if(t1=='6')
            {
                char t;
                cout<<"更改班级：" <<endl;
                cin>>t;
                a[i].info.clas=t;
                cout<<"班级修改成功！"<<endl;
            }

        }
    }

    if(!flag)
    {
        cout<<"查无此人！"<<endl;
    }


}

