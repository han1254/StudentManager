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
        system("CLS");//����
        cout<<"*******************************************************************************************************************"<<endl;
		cout<<"*******************************************************************************************************************"<<endl;
		cout<<"*******************************************************************************************************************"<<endl;
		cout<<"************************************       ѧ���ɼ�����ϵͳ  <����1.0>        *************************************"<<endl;
        cout<<endl<<endl<<endl;
        cout<<"                                                ��ѡ���������"<<endl;
        cout<<endl;
        cout<<"                                       Сѧ����1�� ��������2�� ��ѧ����3��" <<endl;
        int select;



        cin>>select;
        if(select==1)
        {

            while(1)
            {

                system("CLS");//����
                printf("\n\n\n������������������������������������������������������������������������\n");
                cout<<" |   ��1��¼��     ��2�����       | \n |   ��3������     ��4��ɾ��       |\n |   ��5������     ��6��ͳ��       |\n |   ��7��������Ϣ ��0���˳�       |"<<endl;
                printf("������������������������������������������������������������������������\n");
                int s_fun1;
                cin>>s_fun1;
                if(s_fun1==1)
                {
                    system("title ѧ���ɼ�ͳ��ϵͳ-¼��");//������������Ϊ��ѧ���ɼ�ͳ��ϵͳ��


                    char conti;
                    while(1)
                    {
                    	system("CLS");//����
                        bool flag=true;
                        if (t1[primary_num].set_info())
                        {
                            t1[primary_num].set_score();
                        }
                        else
                        {
                            continue;
                        }

                        cout<<"�Ƿ񱣴��޸ģ�Y / N"<<endl;
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
                            cout<<"����δ����.........."<<endl;
                        }
                        cout<<"�Ƿ��������ɼ�Y/N"<<endl;
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
                    {system("CLS");//����
                        char w;
                        printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

                        cout<<setw(12)<<"| ���� |"<< setw(12)<<"| �Ա� |"<<setw(12)<<"|     ѧ��   |"<<setw(12)<<"| �꼶 |" <<setw(12)<<"| �༶ |"<<setw(12)<<"| Ӣ�� |" <<setw(12)<<"| ��ѧ |"<<setw(12)<<"| ���� |" <<setw(12)<<"| �ܷ� |"<<endl;
                        printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
                        for(int i=0; i<primary_num; i++)
                        {
                            show(&t1[i]);

                        }
                        cout<<"����N����ѡ��˵�..........."<<endl;
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
                    {system("CLS");//����
                        char u;
                        search(t1,primary_num);
                        cout<<"�Ƿ�������ң�N/Y"<<endl;
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
                    {system("CLS");//����
                        char r;
                        delet(t1,primary_num);
                        primary_write(t1,primary_num);
                        cout<<"�Ƿ����ɾ����N/Y"<<endl;
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
                    {system("CLS");//����
                        cout<<"****************************************��ѡ����������ʽ**********************************************"<<endl;
                        printf("                ����������������������������������������������������������������\n") ;
                        printf("                �U       ���ܳɼ�������1��              �����Ƴɼ�������2��   �U\n") ;
                        printf("                ����������������������������������������������������������������\n") ;
                        char t;
                        char m;
                        cin>>m;
                        if(m=='1')
                        {
                            sort_(t1);
                        }
                        else if(m=='2')
                        {
                            cout<<"��ѡ������ο���Ŀ��"<<endl;
                            printf("          ������������������������������������������������\n") ;
                            printf("          �U   Ӣ�1��      ��ѧ��2��      ���ģ�3��  �U\n");
                            printf("          ������������������������������������������������\n") ;
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

                        cout<<"�Ƿ�������� Y / N"<<endl;
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
                //����ʧ��


                else if(s_fun1==6)
                {
                    while(1)
                    {system("CLS");//����
                        statis(t1);
                        cout<<"�Ƿ����ͳ�� Y / N" <<endl;
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
                    {system("CLS");//����
                        char out;
                        char sav;
                        edit(t1,primary_num);
                        cout<<"�Ƿ񱣴���ģ�Y / N"<<endl;
                        cin>>sav;
                        if(sav=='Y')
                        {
                            primary_write(t1,primary_num);
                            Sleep(1000);
                            cout<<"�޸ı���ɹ���"<<endl;
                        }
                        else
                        {
                            cout<<"�޸�δ����........."<<endl;
                        }

                        cout<<"�Ƿ��˳��޸�ģ�飿"<<endl
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
                    cout<<"�Ƿ񱣴���ģ�"<<endl;
                    primary_write(t1,primary_num);
                    cout<<"����N�˳�........"<<endl;
                    cin>>t;
                    if(t=='N')
                        break;

                }
                else if(s_fun1==0)
                {
                    break;
                }
                cout<<"�Ƿ񷵻��ϲ�˵���" <<endl;
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
            {system("CLS");//����
                system("CLS");//����
                printf("\n\n\n������������������������������������������������������������������������\n");
                cout<<" |   ��1��¼��     ��2�����       | \n |   ��3������     ��4��ɾ��       |\n |   ��5������     ��6��ͳ��       |\n |   ��7��������Ϣ ��0���˳�       |"<<endl;
                printf("������������������������������������������������������������������������\n");
                int s_fun1;
                cin>>s_fun1;
                if(s_fun1==1)
                {
                    system("title ѧ���ɼ�ͳ��ϵͳ-¼��");//������������Ϊ��ѧ���ɼ�ͳ��ϵͳ��


                    char conti;
                    while(1)
                    {system("CLS");//����
                        bool flag=true;
                        if (t2[high_num].set_info())
                        {
                            t2[high_num].set_score();
                        }
                        else
                        {
                            continue;
                        }

                        cout<<"�Ƿ񱣴��޸ģ�Y / N"<<endl;
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
                            cout<<"����δ����.........."<<endl;
                        }
                        cout<<"�Ƿ��������ɼ�Y/N"<<endl;
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
                    {system("CLS");//����
                        char w;
                        printf(" ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

                        cout<<setw(10)<<"| ���� |" <<setw(10)<<"| �Ա� |"<<setw(10)<<"|     ѧ��   |"<<setw(10)<<"| �꼶 |" <<setw(10)<<"| �༶ |"<<setw(10)<<"| Ӣ�� |" <<setw(10)<<"| ��ѧ |"<<setw(10)<<"| ���� |" <<setw(10)<<"| ��ʷ |"<<setw(10)<<"| ���� |"<<setw(10)<<"| �ܷ� |"<<endl;
                        printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
                        for(int i=0; i<high_num; i++)
                        {
                            show(&t2[i]);

                        }
                        cout<<"����N����ѡ��˵�..........."<<endl;
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
                    {system("CLS");//����
                        char u;
                        search(t2,high_num);
                        cout<<"�Ƿ�������ң�N/Y"<<endl;
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
                    {system("CLS");//����
                        char r;
                        delet(t2,high_num);
                        high_write(t2,high_num);
                        cout<<"�Ƿ����ɾ����N/Y"<<endl;
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
                    {system("CLS");//����
                        cout<<"****************************************��ѡ����������ʽ**********************************************"<<endl;
                        printf("                ����������������������������������������������������������������\n") ;
                        printf("                �U       ���ܳɼ�������1��              �����Ƴɼ�������2��   �U\n") ;
                        printf("                ����������������������������������������������������������������\n") ;
                        char t;
                        char m;
                        cin>>m;
                        if(m=='1')
                        {
                            sort_(t2);
                        }
                        else if(m=='2')
                        {
                            cout<<"��ѡ������ο���Ŀ��"<<endl;
                            printf("          ������������������������������������������������������������������������\n") ;
                            printf("          �U   Ӣ�1��      ���ģ�2��      ��ѧ��3��    ��ʷ��4��  ����5��  �U\n");
                            printf("          ������������������������������������������������������������������������\n") ;
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

                        cout<<"�Ƿ�������� Y / N"<<endl;
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
                    {system("CLS");//����
                        system("CLS");//����
                        statis(t2);
                        cout<<"�Ƿ����ͳ�� Y / N" <<endl;
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
                    {system("CLS");//����
                        char out;
                        char sav;
                        edit(t2,high_num);
                        cout<<"�Ƿ񱣴���ģ�Y / N"<<endl;
                        cin>>sav;
                        if(sav=='Y')
                        {
                            high_write(t2,high_num);
                            Sleep(1000);
                            cout<<"�޸ı���ɹ���"<<endl;
                        }
                        else
                        {
                            cout<<"�޸�δ����........."<<endl;
                        }

                        cout<<"�Ƿ��˳��޸�ģ�飿"<<endl
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
            {system("CLS");//����
                system("CLS");//����
                printf("\n\n\n������������������������������������������������������������������������\n");
                cout<<" |   ��1��¼��     ��2�����       | \n |   ��3������     ��4��ɾ��       |\n |   ��5������     ��6��ͳ��       |\n |   ��7��������Ϣ ��0���˳�       |"<<endl;
                printf("������������������������������������������������������������������������\n");
                int s_fun1;
                cin>>s_fun1;
                if(s_fun1==1)
                {
                    system("title ѧ���ɼ�ͳ��ϵͳ-¼��");//������������Ϊ��ѧ���ɼ�ͳ��ϵͳ��


                    char conti;
                    while(1)
                    {system("CLS");//����
                        bool flag=true;
                        if (t3[college_num].set_info())
                        {
                            t3[college_num].set_score();
                        }
                        else
                        {
                            continue;
                        }

                        cout<<"�Ƿ񱣴��޸ģ�Y / N"<<endl;
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
                            cout<<"����δ����.........."<<endl;
                        }
                        cout<<"�Ƿ��������ɼ�Y/N"<<endl;
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
                    {system("CLS");//����
                        char w;
                        printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

                        cout<<setw(10)<<"| ���� |" <<setw(10)<<"| �Ա� |"<<setw(10)<<"|     ѧ��   |"<<setw(10)<<"| �꼶 |" <<setw(10)<<"| �༶ |"<<setw(10)<<"| Ӣ�� |" <<setw(10)<<"| ���� |"<<setw(10)<<"| רҵ |" <<setw(10)<<"| ������� |"<<setw(10)<<"| �ܷ� |"<<endl;
                        printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
                        for(int i=0; i<college_num; i++)
                        {
                            show(&t3[i]);

                        }
                        cout<<"����N����ѡ��˵�..........."<<endl;
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
                    {system("CLS");//����
                        char u;
                        search(t3,college_num);
                        cout<<"�Ƿ�������ң�N/Y"<<endl;
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
                    {system("CLS");//����
                        char r;
                        delet(t3,college_num);
                        college_write(t3,college_num);
                        cout<<"�Ƿ����ɾ����N/Y"<<endl;
                        cin>>r;
                        if(r=='N')
                            break;
                        else if(r=='Y')
                            continue;
                    }
                }
                else if(s_fun1==5)
                {//����

                    while(1)
                    {/**/system("CLS");
                        cout<<"****************************************��ѡ����������ʽ**********************************************"<<endl;
                        printf("                ����������������������������������������������������������������\n") ;
                        printf("                �U       ���ܳɼ�������1��              �����Ƴɼ�������2��   �U\n") ;
                        printf("                ����������������������������������������������������������������\n") ;
                        char t;
                        char m;
                        cin>>m;
                        if(m=='1')
                        {
                            sort_(t3);
                        }
                        else if(m=='2')
                        {
                            cout<<"��ѡ������ο���Ŀ��"<<endl;
                            printf("          ������������������������������������������������������������������\n") ;
                            printf("          �U   Ӣ�1��      ������2��      רҵ��3��    ������ƣ�4��   �U\n");
                            printf("          ������������������������������������������������������������������\n") ;
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
                    cout<<"�Ƿ�������� Y / N"<<endl;
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
                    {system("CLS");//����
                        system("CLS");//����
                        statis(t2);
                        cout<<"�Ƿ����ͳ�� Y / N" <<endl;
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
                    {system("CLS");//����
                        char out;
                        char sav;
                        edit(t3,college_num);
                        cout<<"�Ƿ񱣴���ģ�Y / N"<<endl;
                        cin>>sav;
                        if(sav=='Y')
                        {
                            college_write(t3,college_num);
                            cout<<"�޸ı���ɹ���"<<endl;
                        }
                        else
                        {
                            cout<<"�޸�δ����........."<<endl;
                        }

                        cout<<"�Ƿ��˳��޸�ģ�飿"<<endl
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


