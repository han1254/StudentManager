#include "student.h"
#include "han.h"
#include "primary.h"
#include "high.h"
#include "college.h"
primary* primary::myPosition = NULL;
bool primary::set_info()
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
    if (!check_(primary::myPosition))
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
void primary::set_score()
{
    double a,b,c;
    cout<<"������ Ӣ���ѧ�����ĵĳɼ���"<<endl;
    cin>>a>>b>>c;
    s_english = a;
    s_math = b;
    s_chinese = c;
    s_sum=s_english+s_math+s_chinese;
}
void primary::show_info()
{
    INFO t;
    t = get_info();
    cout<<setw(10)<<get_info().name<<setw(12)<<get_info().sex <<setw(13)<<get_info().id<<setw(12)<<get_info().grade <<setw(12)<<get_info().clas<<setw(12)<<this->s_english <<setw(12)
        <<this->s_math<<setw(12)<<this->s_chinese <<setw(12)<<this->s_sum<<endl;
    printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
}
void primary_read(primary*a,int n)
{
    ifstream infile1("primary.dat");

    if(!infile1.is_open())
    {
        cout<<"Сѧ���ļ���ʧ�ܣ�"<<endl;
        exit(1);
    }
    else
    {

        while(1)
        {
            infile1>>a[primary_num].info.id;
            infile1>>a[primary_num].info.name;
            infile1>>a[primary_num].info.sex;
            infile1>>a[primary_num].info.age;
            infile1>>a[primary_num].info.grade;
            infile1>>a[primary_num].info.clas;
            infile1>>a[primary_num].s_english;
            infile1>>a[primary_num].s_math;
            infile1>>a[primary_num].s_chinese;
            infile1>>a[primary_num].s_sum;
            primary_num++;
            if(!infile1)
            {
                primary_num--;
                break;
            }
        }

    }
    infile1.close();
}
void primary_write(primary*a,int n)
{
    ofstream outfile1("primary.dat", ios::trunc);
    if(!outfile1)
    {
        cout<<"��Сѧ���ļ�ʧ�ܣ�"<<endl;
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
            outfile1<<a[i].s_sum<<" "<<endl;
        }
    }
    outfile1.close();
}
void search(primary* a, int n)
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

                cout<<setw(12)<<"| ���� |"<< setw(12)<<"| �Ա� |"<<setw(12)<<"|     ѧ��   |"<<setw(12)<<"| �꼶 |" <<setw(12)<<"| �༶ |"<<setw(12)<<"| Ӣ�� |" <<setw(12)<<"| ��ѧ |"<<setw(12)<<"| ���� |" <<setw(12)<<"| �ܷ� |"<<endl;
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
                printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

                cout<<setw(12)<<"| ���� |"<< setw(12)<<"| �Ա� |"<<setw(12)<<"|     ѧ��   |"<<setw(12)<<"| �꼶 |" <<setw(12)<<"| �༶ |"<<setw(12)<<"| Ӣ�� |" <<setw(12)<<"| ��ѧ |"<<setw(12)<<"| ���� |" <<setw(12)<<"| �ܷ� |"<<endl;
                printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
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
void delet(primary *a,int n)
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
            primary_num--;
        }
    }
    if(!flag)
    {
        cout<<"���޴��ˣ�"<<endl;
    }

}
bool  myCompare1(const primary &a1,const primary &a2)//�Զ�������
{
    return a1.s_sum>=a2.s_sum;//��С��������
}
bool myCompare1_eng(const primary &a1, const primary &a2)
{
    return a1.s_english>=a2.s_english;
}
bool myCompare1_chi(const primary &a1, const primary &a2)
{
    return a1.s_chinese>=a2.s_chinese;
}
bool myCompare1_mat(const primary &a1, const primary &a2)
{
    return a1.s_math>=a2.s_math;
}

void sort_(primary *a)
{
    vector <primary> va;
    for(int i=0; i<primary_num; i++)
    {
        va.push_back(a[i]);
    }
    sort(va.begin(),va.end(),myCompare1);


    for (int i = 0; i < primary_num; i++)
    {
        a[i] = va[i];
    }

    cout<<"���ǳɼ����������ܳɼ�����"<<endl;
    printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

    cout<<setw(12)<<"| ���� |" <<setw(12)<<"|     ѧ��   |"<<setw(12)<<"| �꼶 |" <<setw(12)<<"| �༶ |"<<setw(12)<<"| Ӣ�� |" <<setw(12)<<"| ��ѧ |"<<setw(12)<<"| ���� |" <<setw(12)<<"| �ܷ� |"<<setw(12)<<"| ���� |"<<endl;
    printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    for(int i=0; i<primary_num; i++)
    {

        cout<<setw(10)<<a[i].info.name <<setw(13)<<a[i].info.id<<setw(12)<<a[i].info.grade <<setw(12)<<a[i].info.clas<<setw(12)<<a[i].s_english <<setw(12)
            <<a[i].s_math<<setw(12)<<a[i].s_chinese <<setw(12)<<a[i].s_sum<<setw(12)<<i+1<<endl;
        printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    }
}
void sort_1(primary *a)
{
    vector <primary> va;
    for(int i=0; i<primary_num; i++)
    {
        va.push_back(a[i]);
    }
    sort(va.begin(),va.end(),myCompare1_eng);
    for (int i = 0; i < primary_num; i++)
    {
        a[i] = va[i];
    }
    cout<<"���ǳɼ���������Ӣ��ɼ�����"<<endl;
    printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

    cout<<setw(12)<<"| ���� |"<<setw(10)<<"| �Ա� |" <<setw(12)<<"|     ѧ��   |"<<setw(12)<<"| �꼶 |" <<setw(12)<<"| �༶ |"<<setw(12)<<"| Ӣ�� |" <<setw(12)<<"| ���� |"<<endl;
    printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    for(int i=0; i<primary_num; i++)
    {
        cout<<setw(10)<<a[i].info.name <<setw(10)<<a[i].info.sex<<setw(13)<<a[i].info.id<<setw(12)<<a[i].info.grade <<setw(12)<<a[i].info.clas<<setw(12)<<a[i].s_english <<setw(12)<<i+1<<endl;
        printf(" ������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    }

}
void sort_2(primary *a)
{
    vector <primary> va;
    for(int i=0; i<primary_num; i++)
    {
        va.push_back(a[i]);
    }
    sort(va.begin(),va.end(),myCompare1_chi);
    for (int i = 0; i < primary_num; i++)
    {
        a[i] = va[i];
    }
    cout<<"���ǳɼ������������ĳɼ�����"<<endl;
    printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

    cout<<setw(12)<<"| ���� |"<<setw(10)<<"| �Ա� |" <<setw(12)<<"|     ѧ��   |"<<setw(12)<<"| �꼶 |" <<setw(12)<<"| �༶ |"<<setw(12)<<"| ���� |" <<setw(12)<<"| ���� |"<<endl;
    printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    for(int i=0; i<primary_num; i++)
    {
        cout<<setw(10)<<a[i].info.name <<setw(10)<<a[i].info.sex<<setw(13)<<a[i].info.id<<setw(12)<<a[i].info.grade <<setw(12)<<a[i].info.clas<<setw(12)<<a[i].s_chinese <<setw(12)<<i+1<<endl;
        printf(" ������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    }
}
void sort_3(primary *a)
{
    vector <primary> va;
    for(int i=0; i<primary_num; i++)
    {
        va.push_back(a[i]);
    }
    sort(va.begin(),va.end(),myCompare1_mat);
    for (int i = 0; i < primary_num; i++)
    {
        a[i] = va[i];
    }
    cout<<"���ǳɼ�����������ѧ�ɼ�����"<<endl;
    printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

    cout<<setw(12)<<"| ���� |"<<setw(10)<<"| �Ա� |" <<setw(12)<<"|     ѧ��   |"<<setw(12)<<"| �꼶 |" <<setw(12)<<"| �༶ |"<<setw(12)<<"| ��ѧ |" <<setw(12)<<"| ���� |"<<endl;
    printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    for(int i=0; i<primary_num; i++)
    {
        cout<<setw(10)<<a[i].info.name <<setw(10)<<a[i].info.sex<<setw(13)<<a[i].info.id<<setw(12)<<a[i].info.grade <<setw(12)<<a[i].info.clas<<setw(12)<<a[i].s_math <<setw(12)<<i+1<<endl;
        printf(" ������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    }

}
void  statis(primary *a)
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
        cout<<"Ŀǰ���꼶������Ϊ��"<<primary_num<<"��"<<endl;
    }
    else if(t1=='2')
    {
        cout<<"����鿴��һ�Ƶĳɼ��ֲ���"<<endl;
        printf("          ����������������������������������������������������������\n") ;
        printf("          �U Ӣ�1��     ���ģ�2��    ��ѧ��3��    �ܳɼ���4��  �U\n");
        printf("          ����������������������������������������������������������\n") ;
        cin>>t2;
        if(t2=='1')
        {
            int eng1=0;
            int eng2=0;
            int eng3=0;
            for(int i=0; i<primary_num; i++)
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
            for(int i=0; i<primary_num; i++)
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
            for(int i=0; i<primary_num; i++)
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
            int sum1=0;
            int sum2=0;
            int sum3=0;
            for(int i=0; i<primary_num; i++)
            {
                if(a[i].s_sum<180)
                {
                    sum1++;
                }
                else if(a[i].s_sum>=180&&a[i].s_sum<=240)
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
        printf("          ����������������������������������������������������������\n") ;
        printf("          �U Ӣ�1��     ���ģ�2��    ��ѧ��3��    �ܳɼ���4��  �U\n");
        printf("          ����������������������������������������������������������\n") ;
        cin>>t2;
        if(t2=='1')
        {
            double ave;
            int s=0;
            for(int i=0; i<primary_num; i++)
            {
                s+=a[i].s_english;
            }
            ave=s/primary_num;
            printf("Ӣ��ɼ�Ϊ��%.1lf\n",ave);
        }
        else if(t2=='2')
        {
            double ave;
            double s=0.0;
            for(int i=0; i<primary_num; i++)
            {
                s+=a[i].s_chinese;
            }
            ave=s/primary_num;
            /*cout<<"����ƽ���ɼ�Ϊ��"<<s<<endl; */
            printf("���ĳɼ���%.1lf\n",ave);
        }
        else if(t2=='3')
        {
            double ave;
            double s=0.0;
            for(int i=0; i<primary_num; i++)
            {
                s+=a[i].s_math;
            }
            ave=s/primary_num;
            /*cout<<"����ƽ���ɼ�Ϊ��"<<s<<endl; */
            printf("��ѧ�ɼ���%.1lf\n",ave);
        }
        else if(t2=='4')
        {
            double ave;
            double s=0.0;
            for(int i=0; i<primary_num; i++)
            {
                s+=a[i].s_sum;
            }
            ave=s/primary_num;
            /*cout<<"����ƽ���ɼ�Ϊ��"<<s<<endl; */
            printf("��ƽ���ɼ���%.1lf\n",ave);
        }
    }

}
void edit(primary *a,int n)
{


    bool flag=false;

    string str;

    cout<<"������Ҫ���ĵ�ѧ����ѧ�ţ�"<<endl;
    cin>>str;
    for(int i=0; i<n; i++)
    {
        if(a[i].get_info().id==str)
        {
            printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

            cout<<setw(12)<<"| ���� |"<< setw(12)<<"| �Ա� |"<<setw(12)<<"|     ѧ��   |"<<setw(12)<<"| �꼶 |" <<setw(12)<<"| �༶ |"<<setw(12)<<"| Ӣ�� |" <<setw(12)<<"| ��ѧ |"<<setw(12)<<"| ���� |" <<setw(12)<<"| �ܷ� |"<<endl;
            printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            student* t = &a[i];
            show(t);
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
                cout<<"ѡ����Ҫ�޸ĵĳɼ�����1��Ӣ�� ��2������ ��3����ѧ ��4����ȫҪ��"<<endl;

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
                    cout<<"����Ӣ����ģ���ѧ�ɼ���" <<endl;
                    int eng,chi,mat;
                    cin>>eng>>chi>>mat;
                    a[i].s_english=eng;
                    a[i].s_chinese=chi;
                    a[i].s_math=mat;
                    a[i].s_sum=eng+chi+mat;
                    cout<<"�ɼ��޸ĳɹ���"<<endl;
                }
                a[i].s_sum=a[i].s_english+a[i].s_chinese+a[i].s_math;

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

