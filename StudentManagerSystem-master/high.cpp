#include "student.h"
#include "han.h"
#include "primary.h"
#include "high.h"
#include "college.h"
high* high::myPosition1= NULL;
bool high::set_info()
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
    if (!check_1(high::myPosition1))
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
void high::set_score()
{
    double a,b,c,d,e;
    cout<<"请输入 英语，数学，语文，历史，地理的成绩："<<endl;
    cin>>a>>b>>c>>d>>e;
    s_english = a;
    s_math = b;
    s_chinese = c;
    s_history=d;
    s_geog=e;
    s_sum=s_english+s_math+s_chinese+s_history+s_geog;
}
void high::show_info()
{
    INFO t;
    t = get_info();
    cout<<setw(8)<<get_info().name <<setw(10)<<get_info().sex<<setw(12)<<get_info().id<<setw(11)<<get_info().grade <<setw(10)<<get_info().clas<<setw(10)<<this->s_english <<setw(10)
        <<this->s_math<<setw(10)<<this->s_chinese <<setw(10)<<s_history<<setw(10)<<s_geog<<setw(10)<<this->s_sum<<endl;
    printf(" ───────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
}
void high_read(high*a,int n)
{
    ifstream infile1("high.dat");
    if(!infile1)
    {
        cout<<"中学生文件打开失败！"<<endl;
        exit(1);
    }
    else
    {

        while(1)
        {
            infile1>>a[high_num].info.id;
            infile1>>a[high_num].info.name;
            infile1>>a[high_num].info.sex;
            infile1>>a[high_num].info.age;
            infile1>>a[high_num].info.grade;
            infile1>>a[high_num].info.clas;
            infile1>>a[high_num].s_english;
            infile1>>a[high_num].s_math;
            infile1>>a[high_num].s_chinese;
            infile1>>a[high_num].s_history;
            infile1>>a[high_num].s_geog;
            infile1>>a[high_num].s_sum;
            high_num++;
            if(!infile1)
            {
                high_num--;
                break;
            }
        }

    }
}
void high_write(high*a,int n)
{
    ofstream outfile1("high.dat");
    if(!outfile1)
    {
        cout<<"打开中学生文件失败！"<<endl;
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
            outfile1<<a[i].s_chinese<<" ";
            outfile1<<a[i].s_math<<" ";
            outfile1<<a[i].s_history<<" " ;
            outfile1<<a[i].s_geog<<" ";
            outfile1<<a[i].s_sum<<" "<<endl;
        }
    }
}
void search(high* a, int n)
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

                cout<<setw(10)<<"| 姓名 |"<<setw(10)<<"| 性别 |"  <<setw(10)<<"|     学号   |"<<setw(10)<<"| 年级 |" <<setw(10)<<"| 班级 |"<<setw(10)<<"| 英语 |" <<setw(10)<<"| 数学 |"<<setw(10)<<"| 语文 |"<<setw(10)<<"| 历史 |" <<setw(10)<<"| 地理 |"<<setw(10)<<"| 总分 |"<<endl;
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
                printf(" ───────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

                 cout<<setw(10)<<"| 姓名 |" <<setw(10)<<"| 性别 |"<<setw(10)<<"|     学号   |"<<setw(10)<<"| 年级 |" <<setw(10)<<"| 班级 |"<<setw(10)<<"| 英语 |" <<setw(10)<<"| 数学 |"<<setw(10)<<"| 语文 |" <<setw(10)<<"| 历史 |"<<setw(10)<<"| 地理 |"<<setw(10)<<"| 总分 |"<<endl;
                        printf("└───────────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
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
void delet(high *a,int n)
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
            high_num--;
        }
    }
    if(!flag)
    {
        cout<<"查无此人！"<<endl;
    }

}
bool  myCompare2(const high &a1,const high &a2)//自定义排序
{
    return a1.s_sum>=a2.s_sum;//从小到大排序
}
bool myCompare2_eng(const high &a1, const high &a2)
{
    return a1.s_english>=a2.s_english;
}
bool myCompare2_chi(const high &a1, const high &a2)
{
    return a1.s_chinese>=a2.s_chinese;
}
bool myCompare2_mat(const high &a1, const high &a2)
{
    return a1.s_math>=a2.s_math;
}
bool myCompare2_his(const high &a1, const high &a2)//
{
    return a1.s_history>=a2.s_history;             //
}
bool myCompare2_geo(const high &a1, const high &a2)
{
    return a1.s_geog>=a2.s_geog;
}

void sort_(high *a)
{
    vector <high> va;
    for(int i=0; i<high_num; i++)
    {
        va.push_back(a[i]);
    }
    sort(va.begin(),va.end(),myCompare2);


    for (int i = 0; i < high_num; i++)
    {
        a[i] = va[i];
    }

    cout<<"这是成绩排名（按总成绩）："<<endl;
    printf(" ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

    cout<<setw(10)<<"| 姓名 |" <<setw(10)<<"|     学号   |"<<setw(10)<<"| 年级 |" <<setw(10)<<"| 班级 |"<<setw(10)<<"| 英语 |" <<setw(10)<<"| 数学 |"<<setw(10)<<"| 语文 |"<<setw(10)<<"| 历史 |" <<setw(10)<<"| 地理 |"<<setw(10)<<"| 总分 |"<<setw(10)<<"| 名次 |"<<endl;
    printf("└─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
    for(int i=0; i<high_num; i++)
    {

        cout<<setw(10)<<a[i].info.name <<setw(11)<<a[i].info.id<<setw(10)<<a[i].info.grade <<setw(10)<<a[i].info.clas<<setw(10)<<a[i].s_english <<setw(10)
            <<a[i].s_math<<setw(10)<<a[i].s_chinese <<setw(10)<<a[i].s_history<<setw(10)<<a[i].s_geog<<setw(10)<<a[i].s_sum<<setw(10)<<i+1<<endl;
        printf(" ───────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
    }
}
void sort_1(high *a)
{
    vector <high> va;
    for(int i=0; i<high_num; i++)
    {
        va.push_back(a[i]);
    }
    sort(va.begin(),va.end(),myCompare2_eng);
    for (int i = 0; i < high_num; i++)
    {
        a[i] = va[i];
    }
    cout<<"这是成绩排名（按英语成绩）："<<endl;
    printf(" ──────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

    cout<<setw(12)<<"| 姓名 |" <<setw(12)<<"|     学号   |"<<setw(12)<<"| 年级 |" <<setw(12)<<"| 班级 |"<<setw(12)<<"| 英语 |" <<setw(12)<<"| 名次 |"<<endl;
    printf("└──────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
    for(int i=0; i<high_num; i++)
    {
        cout<<setw(10)<<a[i].info.name <<setw(13)<<a[i].info.id<<setw(12)<<a[i].info.grade <<setw(12)<<a[i].info.clas<<setw(12)<<a[i].s_english <<setw(12)<<i+1<<endl;
        printf(" ──────────────────────────────────────────────────────────────────────────\n");
    }

}
void sort_2(high *a)
{
    vector <high> va;
    for(int i=0; i<high_num; i++)
    {
        va.push_back(a[i]);
    }
    sort(va.begin(),va.end(),myCompare2_chi);
    for (int i = 0; i < high_num; i++)
    {
        a[i] = va[i];
    }
    cout<<"这是成绩排名（按语文成绩）："<<endl;
    printf(" ──────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

    cout<<setw(12)<<"| 姓名 |" <<setw(12)<<"|     学号   |"<<setw(12)<<"| 年级 |" <<setw(12)<<"| 班级 |"<<setw(12)<<"| 语文 |" <<setw(12)<<"| 名次 |"<<endl;
    printf("└──────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
    for(int i=0; i<high_num; i++)
    {
        cout<<setw(10)<<a[i].info.name <<setw(13)<<a[i].info.id<<setw(12)<<a[i].info.grade <<setw(12)<<a[i].info.clas<<setw(12)<<a[i].s_chinese <<setw(12)<<i+1<<endl;
        printf(" ──────────────────────────────────────────────────────────────────────────\n");
    }

}
void sort_3(high *a)
{
    vector <high> va;
    for(int i=0; i<high_num; i++)
    {
        va.push_back(a[i]);
    }
    sort(va.begin(),va.end(),myCompare2_mat);
    for (int i = 0; i < high_num; i++)
    {
        a[i] = va[i];
    }
    cout<<"这是成绩排名（按数学成绩）："<<endl;
    printf(" ──────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

    cout<<setw(12)<<"| 姓名 |" <<setw(12)<<"|     学号   |"<<setw(12)<<"| 年级 |" <<setw(12)<<"| 班级 |"<<setw(12)<<"| 数学 |" <<setw(12)<<"| 名次 |"<<endl;
    printf("└──────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
    for(int i=0; i<high_num; i++)
    {
        cout<<setw(10)<<a[i].info.name <<setw(13)<<a[i].info.id<<setw(12)<<a[i].info.grade <<setw(12)<<a[i].info.clas<<setw(12)<<a[i].s_math<<setw(12)<<i+1<<endl;
        printf(" ──────────────────────────────────────────────────────────────────────────\n");
    }

}
void sort_4(high *a)
{
    vector <high> va;
    for(int i=0; i<high_num; i++)
    {
        va.push_back(a[i]);
    }
    sort(va.begin(),va.end(),myCompare2_his);
    for (int i = 0; i < high_num; i++)
    {
        a[i] = va[i];
    }
    cout<<"这是成绩排名（按历史成绩）："<<endl;
    printf(" ──────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

    cout<<setw(12)<<"| 姓名 |" <<setw(12)<<"|     学号   |"<<setw(12)<<"| 年级 |" <<setw(12)<<"| 班级 |"<<setw(12)<<"| 历史 |" <<setw(12)<<"| 名次 |"<<endl;
    printf("└──────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
    for(int i=0; i<high_num; i++)
    {
        cout<<setw(10)<<a[i].info.name <<setw(13)<<a[i].info.id<<setw(12)<<a[i].info.grade <<setw(12)<<a[i].info.clas<<setw(12)<<a[i].s_history<<setw(12)<<i+1<<endl;
        printf(" ──────────────────────────────────────────────────────────────────────────\n");
    }

}
void sort_5(high *a)
{
    vector <high> va;
    for(int i=0; i<high_num; i++)
    {
        va.push_back(a[i]);
    }
    sort(va.begin(),va.end(),myCompare2_geo);
    for (int i = 0; i < high_num; i++)
    {
        a[i] = va[i];
    }
    cout<<"这是成绩排名（按地理成绩）："<<endl;
    printf(" ──────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

    cout<<setw(12)<<"| 姓名 |" <<setw(12)<<"|     学号   |"<<setw(12)<<"| 年级 |" <<setw(12)<<"| 班级 |"<<setw(12)<<"| 地理 |" <<setw(12)<<"| 名次 |"<<endl;
    printf("└──────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
    for(int i=0; i<high_num; i++)
    {
        cout<<setw(10)<<a[i].info.name <<setw(13)<<a[i].info.id<<setw(12)<<a[i].info.grade <<setw(12)<<a[i].info.clas<<setw(12)<<a[i].s_geog<<setw(12)<<i+1<<endl;
        printf(" ──────────────────────────────────────────────────────────────────────────\n");
    }

}
void  statis(high *a)
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
        cout<<"目前该部分总人数为："<<high_num<<"人"<<endl;
    }
    else if(t1=='2')
    {
        cout<<"您想查看哪一科的成绩分布："<<endl;
        printf("          ┌———————————————————————————————————————┐\n") ;
        printf("          ║ 英语（1）     语文（2）    数学（3）    历史（4）   地理（5）   总成绩（6）  ║\n");
        printf("          └———————————————————————————————————————┘\n") ;
        cin>>t2;
        if(t2=='1')
        {
            int eng1=0;
            int eng2=0;
            int eng3=0;
            for(int i=0; i<high_num; i++)
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
        else if(t2=='2')
        {
            int chi1=0;
            int chi2=0;
            int chi3=0;
            for(int i=0; i<high_num; i++)
            {
                if(a[i].s_chinese<60)
                {
                    chi1++;
                }
                else if(a[i].s_chinese>=60&&a[i].s_chinese<=80)
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
        else if(t2=='3')
        {
            int mat1=0;
            int mat2=0;
            int mat3=0;
            for(int i=0; i<high_num; i++)
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
            int his1=0;
            int his2=0;
            int his3=0;
            for(int i=0; i<high_num; i++)
            {
                if(a[i].s_history<60)
                {
                    his1++;
                }
                else if(a[i].s_history>=60&&a[i].s_history<=80)
                {
                    his2++;
                }
                else
                {
                    his3++;
                }
            }
            printf("          ┌—————————————————┐\n") ;
            printf("          ║  小于60分     60~80    80~100    ║\n");
            printf("          └—————————————————┘\n") ;
            printf("                 %d          %d        %d\n",his1,his2,his3);
        }
        else if(t2=='5')
        {
            int geo1=0;
            int geo2=0;
            int geo3=0;
            for(int i=0; i<high_num; i++)
            {
                if(a[i].s_geog<60)
                {
                    geo1++;
                }
                else if(a[i].s_geog>=60&&a[i].s_geog<=80)
                {
                    geo2++;
                }
                else
                {
                    geo3++;
                }
            }
            printf("          ┌—————————————————┐\n") ;
            printf("          ║  小于60分     60~80    80~100    ║\n");
            printf("          └—————————————————┘\n") ;
            printf("                 %d          %d        %d\n",geo1,geo2,geo3);
        }
        else if(t2=='6')
        {
            int sum1=0;
            int sum2=0;
            int sum3=0;
            for(int i=0; i<high_num; i++)
            {
                if(a[i].s_sum<180)
                {
                    sum1++;
                }
                else if(a[i].s_sum>=300&&a[i].s_math<=400)
                {
                    sum2++;
                }
                else
                {
                    sum3++;
                }
            }
            printf("          ┌—————————————————┐\n");
            printf("          ║  小于180分   180~240   240~300   ║\n");
            printf("          └—————————————————┘\n");
            printf("                 %d          %d        %d\n",sum1,sum2,sum3);
        }

    }
    else if(t1=='3')
    {
        cout<<"您想查看平均成绩的方式："<<endl;
        printf("          ┌————————————————————————————————————┐\n") ;
        printf("          ║ 英语（1）     语文（2）    数学（3）  历史（4） 地理（5）  总成绩（6） ║\n");
        printf("          └————————————————————————————————————┘\n") ;
        cin>>t2;
        if(t2=='1')
        {
            double ave;
            int s=0;
            for(int i=0; i<high_num; i++)
            {
                s+=a[i].s_english;
            }
            ave=s/high_num;
            printf("英语平均成绩为：%.1lf\n",ave);
        }
        else if(t2=='2')
        {
            double ave;
            double s=0.0;
            for(int i=0; i<high_num; i++)
            {
                s+=a[i].s_chinese;
            }
            ave=s/high_num;
            /*cout<<"语文平均成绩为："<<s<<endl; */
            printf("语文平均成绩：%.1lf\n",ave);
        }
        else if(t2=='3')
        {
            double ave;
            double s=0.0;
            for(int i=0; i<high_num; i++)
            {
                s+=a[i].s_math;
            }
            ave=s/high_num;
            /*cout<<"语文平均成绩为："<<s<<endl; */
            printf("数学平均成绩：%.1lf\n",ave);
        }
        else if(t2=='4')
        {
            double ave;
            double s=0.0;
            for(int i=0; i<high_num; i++)
            {
                s+=a[i].s_history;
            }
            ave=s/high_num;
            /*cout<<"语文平均成绩为："<<s<<endl; */
            printf("历史平均成绩：%.1lf\n",ave);
        }
        else if(t2=='4')
        {
            double ave;
            double s=0.0;
            for(int i=0; i<high_num; i++)
            {
                s+=a[i].s_geog;
            }
            ave=s/high_num;
            /*cout<<"语文平均成绩为："<<s<<endl; */
            printf("地理平均成绩：%.1lf\n",ave);
        }
        else if(t2=='6')
        {
            double ave;
            double s=0.0;
            for(int i=0; i<high_num; i++)
            {
                s+=a[i].s_sum;
            }
            ave=s/high_num;
            /*cout<<"语文平均成绩为："<<s<<endl; */
            printf("总平均成绩：%.1lf\n",ave);
        }
    }

}
void edit(high *a,int n)
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
                cout<<"选择你要修改的成绩：（1）英语 （2）语文 （3）数学 （4）历史 （5）地理 （6）我全要改"<<endl;

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
                    a[i].s_chinese=chi;
                    cout<<"语文成绩修改成功！"<<endl;
                }
                else if(t2=='3')
                {
                    cout<<"输入修改后的成绩：" <<endl;
                    int mat;
                    cin>>mat;
                    a[i].s_math=mat;
                    cout<<"数学成绩修改成功！"<<endl;
                }
                else if(t2=='4')
                {
                    cout<<"输入修改后的成绩：" <<endl;
                    int his;
                    cin>>his;
                    a[i].s_history=his;
                    cout<<"历史成绩修改成功！"<<endl;
                }
                else if(t2=='5')
                {
                    cout<<"输入修改后的成绩：" <<endl;
                    int his;
                    cin>>his;
                    a[i].s_geog=his;
                    cout<<"地理成绩修改成功！"<<endl;
                }
                else if(t2=='6')
                {
                    cout<<"输入英语，语文，数学，历史，地理成绩：" <<endl;
                    int eng,chi,mat,his,geo;
                    cin>>eng>>chi>>mat>>his>>geo;
                    a[i].s_english=eng;
                    a[i].s_chinese=chi;
                    a[i].s_math=mat;
                    a[i].s_history=his;
                    a[i].s_geog=geo;
                    a[i].s_sum=eng+chi+mat+his+geo;
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
