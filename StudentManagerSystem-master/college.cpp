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
    cout<<"������id��"<<endl;
    cin>>ID;
    rece(ID);
    if (!check_2(college::myPosition2))
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
void college::set_score()
{
    double a,b,c,d,e;
    cout<<"������ Ӣ�������רҵ��������� �ĳɼ���"<<endl;
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
    printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
}
void college_read(college*a,int n)
{
    ifstream infile1("college.dat");

    if(!infile1.is_open())
    {
        cout<<"��ѧ���ļ���ʧ�ܣ�"<<endl;
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
        cout<<"�򿪴�ѧ���ļ�ʧ�ܣ�"<<endl;
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

                cout<<setw(10)<<"| ���� |"<<setw(10)<<"| �Ա� |"<<setw(10)<<"|     ѧ��   |"<<setw(10)<<"| �꼶 |" <<setw(10)<<"| �༶ |"<<setw(10)<<"| Ӣ�� |" <<setw(10)<<"| ���� |"<<setw(10)<<"| רҵ |" <<setw(10)<<"| ������� |"<<setw(10)<<"| �ܷ� |"<<endl;
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

                cout<<setw(10)<<"| ���� |" <<setw(10)<<"|     ѧ��   |"<<setw(10)<<"| �꼶 |" <<setw(10)<<"| �༶ |"<<setw(10)<<"| Ӣ�� |" <<setw(10)<<"| ���� |"<<setw(10)<<"| רҵ |" <<setw(10)<<"| ������� |"<<setw(10)<<"| �ܷ� |"<<endl;
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

void delet(college *a,int n)
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
            college_num--;
        }
    }
    if(!flag)
    {
        cout<<"���޴��ˣ�"<<endl;
    }

}
bool  myCompare3(const college &a1,const college &a2)//�Զ�������
{
    return a1.s_sum>=a2.s_sum;//��С��������
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

    cout<<"���ǳɼ����������ܳɼ�����"<<endl;
    printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

    cout<<setw(10)<<"| ���� |" <<setw(10)<<"|     ѧ��   |"<<setw(10)<<"| �꼶 |" <<setw(10)<<"| �༶ |"<<setw(10)<<"| Ӣ�� |" <<setw(10)<<"| ���� |"<<setw(10)<<"| רҵ |" <<setw(10)<<"| ������� |"<<setw(10)<<"| �ܷ� |"<<setw(10)<<"| ���� |"<<endl;
    printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    for(int i=0; i<college_num; i++)
    {

        cout<<setw(10)<<a[i].info.name <<setw(11)<<a[i].info.id<<setw(10)<<a[i].info.grade <<setw(10)<<a[i].info.clas<<setw(10)<<a[i].s_english <<setw(10)
            <<a[i].s_math<<setw(10)<<a[i].s_magor <<setw(10)<<a[i].s_c<<setw(12)<<a[i].s_sum<<setw(10)<<i+1<<endl;
        printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
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

    cout<<"���ǳɼ���������Ӣ��ɼ�����"<<endl;
    printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

    cout<<setw(10)<<"| ���� |" <<setw(10)<<"|     ѧ��   |"<<setw(10)<<"| �꼶 |" <<setw(10)<<"| �༶ |"<<setw(10)<<"| Ӣ�� |" <<setw(10)<<"| ���� |"<<endl;
    printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    for(int i=0; i<college_num; i++)
    {

        cout<<setw(10)<<a[i].info.name <<setw(11)<<a[i].info.id<<setw(10)<<a[i].info.grade <<setw(10)<<a[i].info.clas<<setw(10)<<a[i].s_english <<setw(10)<<i+1<<endl;
        printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
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

    cout<<"���ǳɼ��������������ɼ�����"<<endl;
    printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

    cout<<setw(10)<<"| ���� |" <<setw(10)<<"|     ѧ��   |"<<setw(10)<<"| �꼶 |" <<setw(10)<<"| �༶ |"<<setw(10)<<"| ���� |" <<setw(10)<<"| ���� |"<<endl;
    printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    for(int i=0; i<college_num; i++)
    {

        cout<<setw(10)<<a[i].info.name <<setw(11)<<a[i].info.id<<setw(10)<<a[i].info.grade <<setw(10)<<a[i].info.clas<<setw(10)<<a[i].s_math <<setw(10)<<i+1<<endl;
        printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
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

    cout<<"���ǳɼ���������רҵ�ɼ�����"<<endl;
    printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

    cout<<setw(10)<<"| ���� |" <<setw(10)<<"|     ѧ��   |"<<setw(10)<<"| �꼶 |" <<setw(10)<<"| �༶ |"<<setw(10)<<"| רҵ |" <<setw(10)<<"| ���� |"<<endl;
    printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    for(int i=0; i<college_num; i++)
    {

        cout<<setw(10)<<a[i].info.name <<setw(11)<<a[i].info.id<<setw(10)<<a[i].info.grade <<setw(10)<<a[i].info.clas<<setw(10)<<a[i].s_magor <<setw(10)<<i+1<<endl;
        printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
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

    cout<<"���ǳɼ���������������Ƴɼ�����"<<endl;
    printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");

    cout<<setw(10)<<"| ���� |" <<setw(10)<<"|     ѧ��   |"<<setw(10)<<"| �꼶 |" <<setw(10)<<"| �༶ |"<<setw(10)<<"| ������� |" <<setw(10)<<"| ���� |"<<endl;
    printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    for(int i=0; i<college_num; i++)
    {

        cout<<setw(10)<<a[i].info.name <<setw(11)<<a[i].info.id<<setw(10)<<a[i].info.grade <<setw(10)<<a[i].info.clas<<setw(10)<<a[i].s_c <<setw(10)<<i+1<<endl;
        printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    }
}
void  statis(college *a)
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
        cout<<"Ŀǰ���꼶������Ϊ��"<<college_num<<"��"<<endl;
    }
    else if(t1=='2')
    {
        cout<<"����鿴��һ�Ƶĳɼ��ֲ���"<<endl;
        printf("          ������������������������������������������������������������������������\n") ;
        printf("          �U Ӣ�1��     ������2��   רҵ��3��    ������ƣ�4��  �ܳɼ���5��  �U\n");
        printf("          ������������������������������������������������������������������������\n") ;
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
            printf("          ��������������������������������������\n") ;
            printf("          �U  С��60��     60~80    80~100    �U\n");
            printf("          ��������������������������������������\n") ;
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
            printf("          ��������������������������������������\n");
            printf("          �U  С��60��     60~80    80~100    �U\n");
            printf("          ��������������������������������������\n");
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
            printf("          ��������������������������������������\n") ;
            printf("          �U  С��60��     60~80    80~100    �U\n");
            printf("          ��������������������������������������\n") ;
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
            printf("          ��������������������������������������\n") ;
            printf("          �U  С��60��     60~80    80~100    �U\n");
            printf("          ��������������������������������������\n") ;
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
            printf("          ��������������������������������������\n");
            printf("          �U  С��240��   240~320   320~400   �U\n");
            printf("          ��������������������������������������\n");
            printf("                 %d          %d        %d\n",sum1,sum2,sum3);
        }

    }
    else if(t1=='3')
    {
        cout<<"����鿴ƽ���ɼ��ķ�ʽ��"<<endl;
        printf("          ������������������������������������������������������������������������\n") ;
        printf("          �U Ӣ�1��     ������2��   רҵ��3��    ������ƣ�4��  �ܳɼ���5��  �U\n");
        printf("          ������������������������������������������������������������������������\n") ;
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
            printf("Ӣ��ɼ�Ϊ��%.1lf\n",ave);
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
            /*cout<<"����ƽ���ɼ�Ϊ��"<<s<<endl; */
            printf("רҵƽ���ɼ���%.1lf\n",ave);
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
            /*cout<<"����ƽ���ɼ�Ϊ��"<<s<<endl; */
            printf("����ƽ���ɼ���%.1lf\n",ave);
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
            /*cout<<"����ƽ���ɼ�Ϊ��"<<s<<endl; */
            printf("�������ƽ���ɼ���%.1lf\n",ave);
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
            /*cout<<"����ƽ���ɼ�Ϊ��"<<s<<endl; */
            printf("��ƽ���ɼ���%.1lf\n",ave);
        }
    }

}
void edit(college *a,int n)
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
                cout<<"ѡ����Ҫ�޸ĵĳɼ�����1��Ӣ�� ��2������  ��3��רҵ ��4��������� ��5����ȫҪ��"<<endl;

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
                    a[i].s_math=chi;
                    cout<<"�����ɼ��޸ĳɹ���"<<endl;
                }
                else if(t2=='3')
                {
                    cout<<"�����޸ĺ�ĳɼ���" <<endl;
                    int mat;
                    cin>>mat;
                    a[i].s_magor=mat;
                    cout<<"רҵ�ɼ��޸ĳɹ���"<<endl;
                }
                else if(t2=='4')
                {
                    cout<<"�����޸ĺ�ĳɼ���" <<endl;
                    int his;
                    cin>>his;
                    a[i].s_c=his;
                    cout<<"������Ƴɼ��޸ĳɹ���"<<endl;
                }

                else if(t2=='5')
                {
                    cout<<"����Ӣ�������רҵ��������Ƴɼ���" <<endl;
                    int eng,mat,magor,c;
                    cin>>eng>>mat>>magor>>c;
                    a[i].s_english=eng;
                    a[i].s_math=mat;
                    a[i].s_magor=magor;
                    a[i].s_c=c;
                    a[i].s_sum =eng+mat+magor+c;
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

