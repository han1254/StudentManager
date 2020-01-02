#include "student.h"
#include "han.h"
#include "primary.h"
#include "high.h"
#include "college.h"

using namespace std;

int main()
{
    system("color F1");

    primary t1[100];
    high t2[100];
    college t3[100];
    primary_read(t1,primary_num);
    high_read(t2,high_num);
    college_read(t3,college_num);




    primary::myPosition = t1;

    high::myPosition1=t2;

    college::myPosition2=t3;
    while(1)


    {
        system("CLS");//清屏
        cout<<"*******************************************************************************************************************"<<endl;
		cout<<"*******************************************************************************************************************"<<endl;
		cout<<"*******************************************************************************************************************"<<endl;
		cout<<"************************************       学生成绩管理系统  <东秦1.0>        *************************************"<<endl;
        cout<<endl<<endl<<endl;
        cout<<"                                                请选择您的身份"<<endl;
        cout<<endl;
        cout<<"                                       小学生（1） 高中生（2） 大学生（3）" <<endl;
        int select;



        cin>>select;
        if(select==1)
        {

            while(1)
            {

                system("CLS");//清屏
                printf("\n\n\n┌──────────────────────────────────┐\n");
                cout<<" |   （1）录入     （2）输出       | \n |   （3）查找     （4）删除       |\n |   （5）排名     （6）统计       |\n |   （7）更改信息 （0）退出       |"<<endl;
                printf("└──────────────────────────────────┘\n");
                int s_fun1;
                cin>>s_fun1;
                if(s_fun1==1)
                {
                    system("title 学生成绩统计系统-录入");//将标题栏命名为“学生成绩统计系统”


                    char conti;
                    while(1)
                    {
                    	system("CLS");//清屏
                        bool flag=true;
                        if (t1[primary_num].set_info())
                        {
                            t1[primary_num].set_score();
                        }
                        else
                        {
                            continue;
                        }

                        cout<<"是否保存修改？Y / N"<<endl;
                        char sav;
                        cin>>sav;
                        if(sav=='Y')
                        {
                            cout << "test : " << primary_num << endl;
                            primary_num++;
                            primary_write(t1,primary_num);
                        }
                        else
                        {
                            cout<<"数据未保存.........."<<endl;
                        }
                        cout<<"是否继续输入成绩Y/N"<<endl;
                        cin>>conti;

                        if(conti=='Y')
                        {
                            continue;
                        }
                        else if(conti=='N')
                        {
                            break;
                        }

                    }
                }
                else if(s_fun1==2)
                {
                    while(1)
                    {system("CLS");//清屏
                        char w;
                        printf(" ──────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

                        cout<<setw(12)<<"| 姓名 |"<< setw(12)<<"| 性别 |"<<setw(12)<<"|     学号   |"<<setw(12)<<"| 年级 |" <<setw(12)<<"| 班级 |"<<setw(12)<<"| 英语 |" <<setw(12)<<"| 数学 |"<<setw(12)<<"| 语文 |" <<setw(12)<<"| 总分 |"<<endl;
                        printf("└──────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
                        for(int i=0; i<primary_num; i++)
                        {
                            show(&t1[i]);

                        }
                        cout<<"请点击N返回选择菜单..........."<<endl;
                        cin>>w;
                        if(w=='N')
                        {
                            break;
                        }
                    }
                }


                else if(s_fun1==3)
                {

                    while(1)
                    {system("CLS");//清屏
                        char u;
                        search(t1,primary_num);
                        cout<<"是否继续查找？N/Y"<<endl;
                        cin>>u;
                        if(u=='N')
                            break;
                        else if(u=='Y')
                            continue;
                    }
                }
                else if(s_fun1==4)
                {
                    while(1)
                    {system("CLS");//清屏
                        char r;
                        delet(t1,primary_num);
                        primary_write(t1,primary_num);
                        cout<<"是否继续删除？N/Y"<<endl;
                        cin>>r;
                        if(r=='N')
                            break;
                        else if(r=='Y')
                            continue;
                    }
                }


                else if(s_fun1==5)
                {

                    while(1)
                    {system("CLS");//清屏
                        cout<<"****************************************请选择您的排序方式**********************************************"<<endl;
                        printf("                ┌——————————————————————————————┐\n") ;
                        printf("                ║       按总成绩排名（1）              按单科成绩排名（2）   ║\n") ;
                        printf("                └——————————————————————————————┘\n") ;
                        char t;
                        char m;
                        cin>>m;
                        if(m=='1')
                        {
                            sort_(t1);
                        }
                        else if(m=='2')
                        {
                            cout<<"请选择排序参考科目："<<endl;
                            printf("          ┌——————————————————————┐\n") ;
                            printf("          ║   英语（1）      数学（2）      语文（3）  ║\n");
                            printf("          └——————————————————————┘\n") ;
                            char t;
                            cin>>t;
                            if(t=='1')
                            {
                                sort_1(t1);
                            }
                            else if(t=='2')
                            {
                                sort_2(t1);
                            }
                            else if(t=='3')
                            {
                                sort_3(t1);
                            }


                        }

                        cout<<"是否继续排序 Y / N"<<endl;
                        cin>>t;
                        if(t=='Y')
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                //排序失败


                else if(s_fun1==6)
                {
                    while(1)
                    {system("CLS");//清屏
                        statis(t1);
                        cout<<"是否继续统计 Y / N" <<endl;
                        char r2;
                        cin>>r2;
                        if(r2=='N')
                            break;
                        else
                            continue;
                    }
                }

                else if(s_fun1==7)
                {
                    while(1)
                    {system("CLS");//清屏
                        char out;
                        char sav;
                        edit(t1,primary_num);
                        cout<<"是否保存更改？Y / N"<<endl;
                        cin>>sav;
                        if(sav=='Y')
                        {
                            primary_write(t1,primary_num);
                            Sleep(1000);
                            cout<<"修改保存成功！"<<endl;
                        }
                        else
                        {
                            cout<<"修改未保存........."<<endl;
                        }

                        cout<<"是否退出修改模块？"<<endl
                            <<"Y / N"<<endl;
                        cin>>out;
                        if(out=='Y')
                        {
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
                else if(s_fun1==8)
                {
                    char t;
                    cout<<"是否保存更改？"<<endl;
                    primary_write(t1,primary_num);
                    cout<<"输入N退出........"<<endl;
                    cin>>t;
                    if(t=='N')
                        break;

                }
                else if(s_fun1==0)
                {
                    break;
                }
                cout<<"是否返回上层菜单？" <<endl;
                char fahui;
                cin>>fahui;
                if(fahui=='Y')
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
        else if(select==2)
        {
            while(1)
            {system("CLS");//清屏
                system("CLS");//清屏
                printf("\n\n\n┌──────────────────────────────────┐\n");
                cout<<" |   （1）录入     （2）输出       | \n |   （3）查找     （4）删除       |\n |   （5）排名     （6）统计       |\n |   （7）更改信息 （0）退出       |"<<endl;
                printf("└──────────────────────────────────┘\n");
                int s_fun1;
                cin>>s_fun1;
                if(s_fun1==1)
                {
                    system("title 学生成绩统计系统-录入");//将标题栏命名为“学生成绩统计系统”


                    char conti;
                    while(1)
                    {system("CLS");//清屏
                        bool flag=true;
                        if (t2[high_num].set_info())
                        {
                            t2[high_num].set_score();
                        }
                        else
                        {
                            continue;
                        }

                        cout<<"是否保存修改？Y / N"<<endl;
                        char sav;
                        cin>>sav;
                        if(sav=='Y')
                        {
                            cout << "test : " << high_num << endl;
                            high_num++;
                            high_write(t2,high_num);
                        }
                        else
                        {
                            cout<<"数据未保存.........."<<endl;
                        }
                        cout<<"是否继续输入成绩Y/N"<<endl;
                        cin>>conti;

                        if(conti=='Y')
                        {
                            continue;
                        }
                        else if(conti=='N')
                        {
                            break;
                        }

                    }
                }
                else if(s_fun1==2)
                {
                    while(1)
                    {system("CLS");//清屏
                        char w;
                        printf(" ───────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

                        cout<<setw(10)<<"| 姓名 |" <<setw(10)<<"| 性别 |"<<setw(10)<<"|     学号   |"<<setw(10)<<"| 年级 |" <<setw(10)<<"| 班级 |"<<setw(10)<<"| 英语 |" <<setw(10)<<"| 数学 |"<<setw(10)<<"| 语文 |" <<setw(10)<<"| 历史 |"<<setw(10)<<"| 地理 |"<<setw(10)<<"| 总分 |"<<endl;
                        printf("└───────────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
                        for(int i=0; i<high_num; i++)
                        {
                            show(&t2[i]);

                        }
                        cout<<"请点击N返回选择菜单..........."<<endl;
                        cin>>w;
                        if(w=='N')
                        {
                            break;
                        }
                    }
                }
                else if(s_fun1==3)
                {

                    while(1)
                    {system("CLS");//清屏
                        char u;
                        search(t2,high_num);
                        cout<<"是否继续查找？N/Y"<<endl;
                        cin>>u;
                        if(u=='N')
                            break;
                        else if(u=='Y')
                            continue;
                    }
                }
                else if(s_fun1==4)
                {
                    while(1)
                    {system("CLS");//清屏
                        char r;
                        delet(t2,high_num);
                        high_write(t2,high_num);
                        cout<<"是否继续删除？N/Y"<<endl;
                        cin>>r;
                        if(r=='N')
                            break;
                        else if(r=='Y')
                            continue;
                    }
                }
                else if(s_fun1==5)
                {

                    while(1)
                    {system("CLS");//清屏
                        cout<<"****************************************请选择您的排序方式**********************************************"<<endl;
                        printf("                ┌——————————————————————————————┐\n") ;
                        printf("                ║       按总成绩排名（1）              按单科成绩排名（2）   ║\n") ;
                        printf("                └——————————————————————————————┘\n") ;
                        char t;
                        char m;
                        cin>>m;
                        if(m=='1')
                        {
                            sort_(t2);
                        }
                        else if(m=='2')
                        {
                            cout<<"请选择排序参考科目："<<endl;
                            printf("          ┌——————————————————————————————————┐\n") ;
                            printf("          ║   英语（1）      语文（2）      数学（3）    历史（4）  地理（5）  ║\n");
                            printf("          └——————————————————————————————————┘\n") ;
                            char t;
                            cin>>t;
                            if(t=='1')
                            {
                                sort_1(t2);
                            }
                            else if(t=='2')
                            {
                                sort_2(t2);
                            }
                            else if(t=='3')
                            {
                                sort_3(t2);
                            }
                            else if(t=='4')
                            {
                                sort_4(t2);
                            }
                            else if(t=='5')
                            {
                                sort_5(t2);
                            }

                        }

                        cout<<"是否继续排序 Y / N"<<endl;
                        cin>>t;
                        if(t=='Y')
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else if(s_fun1==6)
                {
                    while(1)
                    {system("CLS");//清屏
                        system("CLS");//清屏
                        statis(t2);
                        cout<<"是否继续统计 Y / N" <<endl;
                        char r2;
                        cin>>r2;
                        if(r2=='N')
                            break;
                        else
                            continue;
                    }
                }
                else if(s_fun1==7)
                {
                    while(1)
                    {system("CLS");//清屏
                        char out;
                        char sav;
                        edit(t2,high_num);
                        cout<<"是否保存更改？Y / N"<<endl;
                        cin>>sav;
                        if(sav=='Y')
                        {
                            high_write(t2,high_num);
                            Sleep(1000);
                            cout<<"修改保存成功！"<<endl;
                        }
                        else
                        {
                            cout<<"修改未保存........."<<endl;
                        }

                        cout<<"是否退出修改模块？"<<endl
                            <<"Y / N"<<endl;
                        cin>>out;
                        if(out=='Y')
                        {
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
                else if(s_fun1==0)
                {
                    break;
                }

            }
        }
        else if(select=3)
        {
            while(1)
            {system("CLS");//清屏
                system("CLS");//清屏
                printf("\n\n\n┌──────────────────────────────────┐\n");
                cout<<" |   （1）录入     （2）输出       | \n |   （3）查找     （4）删除       |\n |   （5）排名     （6）统计       |\n |   （7）更改信息 （0）退出       |"<<endl;
                printf("└──────────────────────────────────┘\n");
                int s_fun1;
                cin>>s_fun1;
                if(s_fun1==1)
                {
                    system("title 学生成绩统计系统-录入");//将标题栏命名为“学生成绩统计系统”


                    char conti;
                    while(1)
                    {system("CLS");//清屏
                        bool flag=true;
                        if (t3[college_num].set_info())
                        {
                            t3[college_num].set_score();
                        }
                        else
                        {
                            continue;
                        }

                        cout<<"是否保存修改？Y / N"<<endl;
                        char sav;
                        cin>>sav;
                        if(sav=='Y')
                        {
                            cout << "test : " << college_num << endl;
                            college_num++;
                            college_write(t3,college_num);
                        }
                        else
                        {
                            cout<<"数据未保存.........."<<endl;
                        }
                        cout<<"是否继续输入成绩Y/N"<<endl;
                        cin>>conti;

                        if(conti=='Y')
                        {
                            continue;
                        }
                        else if(conti=='N')
                        {
                            break;
                        }

                    }
                }
                else if(s_fun1==2)
                {
                    while(1)
                    {system("CLS");//清屏
                        char w;
                        printf(" ──────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

                        cout<<setw(10)<<"| 姓名 |" <<setw(10)<<"| 性别 |"<<setw(10)<<"|     学号   |"<<setw(10)<<"| 年级 |" <<setw(10)<<"| 班级 |"<<setw(10)<<"| 英语 |" <<setw(10)<<"| 高数 |"<<setw(10)<<"| 专业 |" <<setw(10)<<"| 程序设计 |"<<setw(10)<<"| 总分 |"<<endl;
                        printf("└──────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
                        for(int i=0; i<college_num; i++)
                        {
                            show(&t3[i]);

                        }
                        cout<<"请点击N返回选择菜单..........."<<endl;
                        cin>>w;
                        if(w=='N')
                        {
                            break;
                        }
                    }
                }
                else if(s_fun1==3)
                {

                    while(1)
                    {system("CLS");//清屏
                        char u;
                        search(t3,college_num);
                        cout<<"是否继续查找？N/Y"<<endl;
                        cin>>u;
                        if(u=='N')
                            break;
                        else if(u=='Y')
                            continue;
                    }
                }
                else if(s_fun1==4)
                {
                    while(1)
                    {system("CLS");//清屏
                        char r;
                        delet(t3,college_num);
                        college_write(t3,college_num);
                        cout<<"是否继续删除？N/Y"<<endl;
                        cin>>r;
                        if(r=='N')
                            break;
                        else if(r=='Y')
                            continue;
                    }
                }
                else if(s_fun1==5)
                {//清屏

                    while(1)
                    {/**/system("CLS");
                        cout<<"****************************************请选择您的排序方式**********************************************"<<endl;
                        printf("                ┌——————————————————————————————┐\n") ;
                        printf("                ║       按总成绩排名（1）              按单科成绩排名（2）   ║\n") ;
                        printf("                └——————————————————————————————┘\n") ;
                        char t;
                        char m;
                        cin>>m;
                        if(m=='1')
                        {
                            sort_(t3);
                        }
                        else if(m=='2')
                        {
                            cout<<"请选择排序参考科目："<<endl;
                            printf("          ┌———————————————————————————————┐\n") ;
                            printf("          ║   英语（1）      高数（2）      专业（3）    程序设计（4）   ║\n");
                            printf("          └———————————————————————————————┘\n") ;
                            char t;
                            cin>>t;
                            if(t=='1')
                            {
                                sort_1(t3);
                            }
                            else if(t=='2')
                            {
                                sort_2(t3);
                            }
                            else if(t=='3')
                            {
                                sort_3(t3);
                            }
                            else if(t=='4')
                            {
                                sort_4(t3);
                            }

                        }
                    cout<<"是否继续排序 Y / N"<<endl;
                    char tm;
                    cin>>tm;
                    if(tm=='Y')
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }

                    }


                }
                else if(s_fun1==6)
                {
                    while(1)
                    {system("CLS");//清屏
                        system("CLS");//清屏
                        statis(t2);
                        cout<<"是否继续统计 Y / N" <<endl;
                        char r2;
                        cin>>r2;
                        if(r2=='N')
                            break;
                        else
                            continue;
                    }
                }

                else if(s_fun1==7)
                {
                    while(1)
                    {system("CLS");//清屏
                        char out;
                        char sav;
                        edit(t3,college_num);
                        cout<<"是否保存更改？Y / N"<<endl;
                        cin>>sav;
                        if(sav=='Y')
                        {
                            college_write(t3,college_num);
                            cout<<"修改保存成功！"<<endl;
                        }
                        else
                        {
                            cout<<"修改未保存........."<<endl;
                        }

                        cout<<"是否退出修改模块？"<<endl
                            <<"Y / N"<<endl;
                        cin>>out;
                        if(out=='Y')
                        {
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
                else if(s_fun1==0)
                {
                    break;
                }

            }

        }

    }
return 0;
}


