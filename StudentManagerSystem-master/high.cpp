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
    cout<<"������id��"<<endl;
    cin>>ID;
    rece(ID);
    if (!check_1(high::myPosition1))
    {
        cout << "�ظ������س�����������..." << endl;
        getchar();
        getchar();
        return false;
    }
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
    return true;
}
void high::set_score()
{
    double a,b,c,d,e;
    cout<<"������ Ӣ���ѧ�����ģ���ʷ������ĳɼ���"<<endl;
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
    printf(" ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
}
void high_read(high*a,int n)
{
    ifstream infile1("high.dat");
    if(!infile1)
    {
        cout<<"��ѧ���ļ���ʧ�ܣ�"<<endl;
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
        cout<<"����ѧ���ļ�ʧ�ܣ�"<<endl;
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
    cout<<"ѡ���ѯ��ʽ��"<<endl;
    printf("          ������������������������������\n") ;
    printf("          �U �����֣�1��  ��ѧ�ţ�2�� �U\n");
    printf("          ������������������������������\n") ;
    cin>>t1;
    if(t1=='1')
    {
        cout<<"���������֣�" <<endl;
        cin>>str;
        for(int i=0; i < n; i++)
        {
            if(str == a[i].get_info().name)
            {
                printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

                cout<<setw(10)<<"| ���� |"<<setw(10)<<"| �Ա� |"  <<setw(10)<<"|     ѧ��   |"<<setw(10)<<"| �꼶 |" <<setw(10)<<"| �༶ |"<<setw(10)<<"| Ӣ�� |" <<setw(10)<<"| ��ѧ |"<<setw(10)<<"| ���� |"<<setw(10)<<"| ��ʷ |" <<setw(10)<<"| ���� |"<<setw(10)<<"| �ܷ� |"<<endl;
                printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

                student* t = &a[i];
                show(t);
                find = true;
            }
        }
    }
    else if(t1=='2')
    {
        cout<<"������ѧ�ţ�"<<endl;
        cin>>str;
        for(int i=0; i < n; i++)
        {
            if(str == a[i].get_info().id)
            {
                printf(" ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

                 cout<<setw(10)<<"| ���� |" <<setw(10)<<"| �Ա� |"<<setw(10)<<"|     ѧ��   |"<<setw(10)<<"| �꼶 |" <<setw(10)<<"| �༶ |"<<setw(10)<<"| Ӣ�� |" <<setw(10)<<"| ��ѧ |"<<setw(10)<<"| ���� |" <<setw(10)<<"| ��ʷ |"<<setw(10)<<"| ���� |"<<setw(10)<<"| �ܷ� |"<<endl;
                        printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
                student* t = &a[i];
                show(t);
                find = true;
            }
        }
    }


    if (!find)
    {
        cout << "���޴��ˣ�" << endl;
    }
}
void delet(high *a,int n)
{
    string t;
    bool flag=false;
    cout<<"��������ɾ����ѧ��ѧ�ţ�"<<endl;
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
        cout<<"���޴��ˣ�"<<endl;
    }

}
bool  myCompare2(const high &a1,const high &a2)//�Զ�������
{
    return a1.s_sum>=a2.s_sum;//��С��������
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

    cout<<"���ǳɼ����������ܳɼ�����"<<endl;
    printf(" ����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

    cout<<setw(10)<<"| ���� |" <<setw(10)<<"|     ѧ��   |"<<setw(10)<<"| �꼶 |" <<setw(10)<<"| �༶ |"<<setw(10)<<"| Ӣ�� |" <<setw(10)<<"| ��ѧ |"<<setw(10)<<"| ���� |"<<setw(10)<<"| ��ʷ |" <<setw(10)<<"| ���� |"<<setw(10)<<"| �ܷ� |"<<setw(10)<<"| ���� |"<<endl;
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    for(int i=0; i<high_num; i++)
    {

        cout<<setw(10)<<a[i].info.name <<setw(11)<<a[i].info.id<<setw(10)<<a[i].info.grade <<setw(10)<<a[i].info.clas<<setw(10)<<a[i].s_english <<setw(10)
            <<a[i].s_math<<setw(10)<<a[i].s_chinese <<setw(10)<<a[i].s_history<<setw(10)<<a[i].s_geog<<setw(10)<<a[i].s_sum<<setw(10)<<i+1<<endl;
        printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
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
    cout<<"���ǳɼ���������Ӣ��ɼ�����"<<endl;
    printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

    cout<<setw(12)<<"| ���� |" <<setw(12)<<"|     ѧ��   |"<<setw(12)<<"| �꼶 |" <<setw(12)<<"| �༶ |"<<setw(12)<<"| Ӣ�� |" <<setw(12)<<"| ���� |"<<endl;
    printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    for(int i=0; i<high_num; i++)
    {
        cout<<setw(10)<<a[i].info.name <<setw(13)<<a[i].info.id<<setw(12)<<a[i].info.grade <<setw(12)<<a[i].info.clas<<setw(12)<<a[i].s_english <<setw(12)<<i+1<<endl;
        printf(" ����������������������������������������������������������������������������������������������������������������������������������������������������\n");
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
    cout<<"���ǳɼ������������ĳɼ�����"<<endl;
    printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

    cout<<setw(12)<<"| ���� |" <<setw(12)<<"|     ѧ��   |"<<setw(12)<<"| �꼶 |" <<setw(12)<<"| �༶ |"<<setw(12)<<"| ���� |" <<setw(12)<<"| ���� |"<<endl;
    printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    for(int i=0; i<high_num; i++)
    {
        cout<<setw(10)<<a[i].info.name <<setw(13)<<a[i].info.id<<setw(12)<<a[i].info.grade <<setw(12)<<a[i].info.clas<<setw(12)<<a[i].s_chinese <<setw(12)<<i+1<<endl;
        printf(" ����������������������������������������������������������������������������������������������������������������������������������������������������\n");
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
    cout<<"���ǳɼ�����������ѧ�ɼ�����"<<endl;
    printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

    cout<<setw(12)<<"| ���� |" <<setw(12)<<"|     ѧ��   |"<<setw(12)<<"| �꼶 |" <<setw(12)<<"| �༶ |"<<setw(12)<<"| ��ѧ |" <<setw(12)<<"| ���� |"<<endl;
    printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    for(int i=0; i<high_num; i++)
    {
        cout<<setw(10)<<a[i].info.name <<setw(13)<<a[i].info.id<<setw(12)<<a[i].info.grade <<setw(12)<<a[i].info.clas<<setw(12)<<a[i].s_math<<setw(12)<<i+1<<endl;
        printf(" ����������������������������������������������������������������������������������������������������������������������������������������������������\n");
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
    cout<<"���ǳɼ�����������ʷ�ɼ�����"<<endl;
    printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

    cout<<setw(12)<<"| ���� |" <<setw(12)<<"|     ѧ��   |"<<setw(12)<<"| �꼶 |" <<setw(12)<<"| �༶ |"<<setw(12)<<"| ��ʷ |" <<setw(12)<<"| ���� |"<<endl;
    printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    for(int i=0; i<high_num; i++)
    {
        cout<<setw(10)<<a[i].info.name <<setw(13)<<a[i].info.id<<setw(12)<<a[i].info.grade <<setw(12)<<a[i].info.clas<<setw(12)<<a[i].s_history<<setw(12)<<i+1<<endl;
        printf(" ����������������������������������������������������������������������������������������������������������������������������������������������������\n");
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
    cout<<"���ǳɼ�������������ɼ�����"<<endl;
    printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

    cout<<setw(12)<<"| ���� |" <<setw(12)<<"|     ѧ��   |"<<setw(12)<<"| �꼶 |" <<setw(12)<<"| �༶ |"<<setw(12)<<"| ���� |" <<setw(12)<<"| ���� |"<<endl;
    printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    for(int i=0; i<high_num; i++)
    {
        cout<<setw(10)<<a[i].info.name <<setw(13)<<a[i].info.id<<setw(12)<<a[i].info.grade <<setw(12)<<a[i].info.clas<<setw(12)<<a[i].s_geog<<setw(12)<<i+1<<endl;
        printf(" ����������������������������������������������������������������������������������������������������������������������������������������������������\n");
    }

}
void  statis(high *a)
{
    char t1;
    char t2;
    char t3;
    cout<<"��ѡ��ͳ�Ʒ�ʽ"<<endl;
    printf("          ����������������������������������������������������������\n") ;
    printf("          �U �鿴��������1�� �鿴�ɼ��ֲ���2�� �鿴ƽ���ɼ���3��  �U\n");
    printf("          ����������������������������������������������������������\n") ;
    cin>>t1;
    if(t1=='1')
    {
        cout<<"Ŀǰ�ò���������Ϊ��"<<high_num<<"��"<<endl;
    }
    else if(t1=='2')
    {
        cout<<"����鿴��һ�Ƶĳɼ��ֲ���"<<endl;
        printf("          ����������������������������������������������������������������������������������\n") ;
        printf("          �U Ӣ�1��     ���ģ�2��    ��ѧ��3��    ��ʷ��4��   ����5��   �ܳɼ���6��  �U\n");
        printf("          ����������������������������������������������������������������������������������\n") ;
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
            printf("          ��������������������������������������\n") ;
            printf("          �U  С��60��     60~80    80~100    �U\n");
            printf("          ��������������������������������������\n") ;
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
            printf("          ��������������������������������������\n");
            printf("          �U  С��60��     60~80    80~100    �U\n");
            printf("          ��������������������������������������\n");
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
            printf("          ��������������������������������������\n") ;
            printf("          �U  С��60��     60~80    80~100    �U\n");
            printf("          ��������������������������������������\n") ;
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
            printf("          ��������������������������������������\n") ;
            printf("          �U  С��60��     60~80    80~100    �U\n");
            printf("          ��������������������������������������\n") ;
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
            printf("          ��������������������������������������\n") ;
            printf("          �U  С��60��     60~80    80~100    �U\n");
            printf("          ��������������������������������������\n") ;
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
            printf("          ��������������������������������������\n");
            printf("          �U  С��180��   180~240   240~300   �U\n");
            printf("          ��������������������������������������\n");
            printf("                 %d          %d        %d\n",sum1,sum2,sum3);
        }

    }
    else if(t1=='3')
    {
        cout<<"����鿴ƽ���ɼ��ķ�ʽ��"<<endl;
        printf("          ����������������������������������������������������������������������������\n") ;
        printf("          �U Ӣ�1��     ���ģ�2��    ��ѧ��3��  ��ʷ��4�� ����5��  �ܳɼ���6�� �U\n");
        printf("          ����������������������������������������������������������������������������\n") ;
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
            printf("Ӣ��ƽ���ɼ�Ϊ��%.1lf\n",ave);
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
            /*cout<<"����ƽ���ɼ�Ϊ��"<<s<<endl; */
            printf("����ƽ���ɼ���%.1lf\n",ave);
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
            /*cout<<"����ƽ���ɼ�Ϊ��"<<s<<endl; */
            printf("��ѧƽ���ɼ���%.1lf\n",ave);
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
            /*cout<<"����ƽ���ɼ�Ϊ��"<<s<<endl; */
            printf("��ʷƽ���ɼ���%.1lf\n",ave);
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
            /*cout<<"����ƽ���ɼ�Ϊ��"<<s<<endl; */
            printf("����ƽ���ɼ���%.1lf\n",ave);
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
            /*cout<<"����ƽ���ɼ�Ϊ��"<<s<<endl; */
            printf("��ƽ���ɼ���%.1lf\n",ave);
        }
    }

}
void edit(high *a,int n)
{


    bool flag=false;

    string str;

    cout<<"������Ҫ���ĵ�ѧ����ѧ�ţ�"<<endl;
    cin>>str;
    for(int i=0; i<n; i++)
    {
        if(a[i].get_info().id==str)
        {
            flag=true;
            cout<<"��ѡ����Ҫ���ĵ���Ŀ��"<<endl;
            cout<<"(1)ѧ�� ��2������ ��3���ɼ� ��4���Ա� (5)�꼶 ��6���༶"<<endl;
            char t1;
            cin>>t1;
            if(t1=='1')
            {
                string c;
                char d;
                cin>>c;
                a[i].info.id=c;
                cout<<"ѧ���޸ĳɹ���"<<endl;
            }
            else if(t1=='2')
            {
                string c;
                cin>>c;
                a[i].info.name=c;
            }
            else if(t1=='3')
            {
                cout<<"ѡ����Ҫ�޸ĵĳɼ�����1��Ӣ�� ��2������ ��3����ѧ ��4����ʷ ��5������ ��6����ȫҪ��"<<endl;

                char t2;
                cin>>t2;
                if(t2=='1')
                {
                    cout<<"�����޸ĺ�ĳɼ���"<<endl;
                    int eng;
                    cin>>eng;
                    a[i].s_english=eng;
                    cout<<"Ӣ��ɼ��޸ĳɹ���"<<endl;
                }
                else if(t2=='2')
                {
                    cout<<"����޸ĺ�ĳɼ���"<<endl;
                    int chi;
                    cin>>chi;
                    a[i].s_chinese=chi;
                    cout<<"���ĳɼ��޸ĳɹ���"<<endl;
                }
                else if(t2=='3')
                {
                    cout<<"�����޸ĺ�ĳɼ���" <<endl;
                    int mat;
                    cin>>mat;
                    a[i].s_math=mat;
                    cout<<"��ѧ�ɼ��޸ĳɹ���"<<endl;
                }
                else if(t2=='4')
                {
                    cout<<"�����޸ĺ�ĳɼ���" <<endl;
                    int his;
                    cin>>his;
                    a[i].s_history=his;
                    cout<<"��ʷ�ɼ��޸ĳɹ���"<<endl;
                }
                else if(t2=='5')
                {
                    cout<<"�����޸ĺ�ĳɼ���" <<endl;
                    int his;
                    cin>>his;
                    a[i].s_geog=his;
                    cout<<"����ɼ��޸ĳɹ���"<<endl;
                }
                else if(t2=='6')
                {
                    cout<<"����Ӣ����ģ���ѧ����ʷ������ɼ���" <<endl;
                    int eng,chi,mat,his,geo;
                    cin>>eng>>chi>>mat>>his>>geo;
                    a[i].s_english=eng;
                    a[i].s_chinese=chi;
                    a[i].s_math=mat;
                    a[i].s_history=his;
                    a[i].s_geog=geo;
                    a[i].s_sum=eng+chi+mat+his+geo;
                    cout<<"�ɼ��޸ĳɹ���"<<endl;
                }

            }
            else if(t1=='4')
            {
                char t;
                cout<<"�����Ա�" <<endl;
                cin>>t;
                a[i].info.sex=t;
                cout<<"�Ա��޸ĳɹ���"<<endl;
            }
            else if(t1=='5')
            {
                char t;
                cout<<"�����꼶��" <<endl;
                cin>>t;
                a[i].info.grade=t;
                cout<<"�꼶�޸ĳɹ���"<<endl;
            }
            else if(t1=='6')
            {
                char t;
                cout<<"���İ༶��" <<endl;
                cin>>t;
                a[i].info.clas=t;
                cout<<"�༶�޸ĳɹ���"<<endl;
            }

        }
    }

    if(!flag)
    {
        cout<<"���޴��ˣ�"<<endl;
    }


}
