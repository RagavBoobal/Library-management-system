#include<iostream>
#include<fstream>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
#include<sstream>
using namespace std;
char asn[100];
int a1=0,a2=0,i;
struct treeNode
{
	char data[6];
	struct treeNode *left,*right;
}*root=NULL;
class book
{
	char bno[6];
	char bname[50];
	char aname[20];
	char nam[50];
  public:
    treeNode* n;
    treeNode* treeInsert(treeNode*,char*);
	void create_book()
	{
        cout<<"\nENTER THE BOOK NUMBER : ";
        cin>>bno;
		root=treeInsert(root,bno);
		x1:
        cout<<"\n\nENTER THE NAME OF THE BOOK : ";
        cin>>nam;
        strcpy(bname,nam);
        cout<<"\n\nENTER THE AUTHOR NAME : ";
        cin>>aname;
    }
    void show_book()
    {
        cout<<"\nBOOK NUMBER : "<<bno;
        cout<<"\nBOOK NAME : ";
        puts(bname);
        cout<<"AUTHOR NAME : ";
        puts(aname);
    }
    char* retbno()
    {
        return bno;
    }
    void report()
    {cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;}
};
class student
{
    char admno[6];
    char name[20];
    char stbno[6];
    char nm[20];
    string dep;
    string  course;
    int token;
public:
    void create_student()
    {
        cout<<"\nENTER THE STUDENT ROLL NUMBER: ";
        cin>>admno;
        a1=a1+1;
        cout<<"\nENTER THE STUDENT'S NAME:";
        cin>>nm;
        strcpy(name,nm);
        cout<<"\n"<<name<<"\n"<<nm;
        cout<<"\nENTER THE DEPARTMENT::";
        cin>>dep;
        cout<<"\nENTER THE COURSE:";
        cin>>course;
        token=0;
        stbno[0]='/0';
    }
    void show_student()
    {
        cout<<"\nROLL NO : "<<admno;
        cout<<"\nSTUDENT NAME : "<<name;
        cout<<"\nNO OF BOOK ISSUED : "<<token;
        if(token==1)
            cout<<"\nBOOK NO : "<<stbno;
        cout<<"\n-----------------";
    }
	char* retadmno()
    {
        return admno;
    }
    char* retstbno()
    {
        return stbno;
    }
    int rettoken()
    {
        return token;
    }
    void addtoken()
    {token=1;}
    void resettoken()
    {token=0;}
    void getstbno(char t[])
    {
        strcpy(stbno,t);
    }
    void report()
    {cout<<"\t"<<admno<<setw(20)<<name<<setw(10)<<token<<endl;}
};
fstream fp,fp1;
book bk;
student st;
treeNode* book::treeInsert(treeNode *node,char* key)
{
	if(node==NULL)
    {
        treeNode *temp;
        temp=new treeNode;
        strcpy(temp -> data,key);
        temp -> left = temp -> right = NULL;
        return temp;
    }
    if(key >(node->data))
    {
        node->right = treeInsert(node->right,key);
    }
    else if(key < (node->data))
    {
        node->left = treeInsert(node->left,key);
    }
    return node;
}
void write_book()
{
    char ch;
    fp.open("book.dat",ios::out|ios::app);
    do
    {
        bk.create_book();
        fp.write((char*)&bk,sizeof(book));
        cout<<"\n\nDo you want to add more record..(y/n?)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}
void write_student()
{
    char ch;
    fp.open("student.dat",ios::out|ios::app);
    do
    {
        st.create_student();
        fp.write((char*)&st,sizeof(student));
        cout<<"\n\nDo you want to add more record..(y/n?)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}
void display_spb(char n[])
{
    cout<<"\nBOOK DETAILS\n";
    int flag=0;
    fp.open("book.dat",ios::in);
    while(fp.read((char*)&bk,sizeof(book)))
    {
        if(strcmp(bk.retbno(),n)==0)
        {
            bk.show_book();
             flag=1;
        }
    }
    fp.close();
    if(flag==0)
        cout<<"\n\nBOOK DOES NOT EXIT : ";
    getch();
}
void display_sps(char n[])
{
    cout<<"\nSTUDENT DETAILS\n";
    int flag=0;
    fp.open("student.dat",ios::in);
    while(fp.read((char*)&st,sizeof(student)))
    {
        if((strcmpi(st.retadmno(),n)==0))
        {
            st.show_student();
            flag=1;
        }
    }
    fp.close();
    if(flag==0)
            cout<<"\n\nSTUDENT DOES NOT EXIT : ";
     getch();
}
void delete_student()
{
    char n[6];
    int flag=0;
        cout<<"\n\n\n\tDELETE STUDENT...";
        cout<<"\n\nENTER THE ROLL NO OF THE STUDENT THAT YOU WANT TO DELETE : ";
        cin>>n;
        fp.open("student.dat",ios::in|ios::out);
        fstream fp2;
        fp2.open("Temp.dat",ios::out);
        fp.seekg(0,ios::beg);
        while(fp.read((char*)&st,sizeof(student)))
    {
        if(strcmpi(st.retadmno(),n)!=0)
                 fp2.write((char*)&st,sizeof(student));
        else
               flag=1;
    }
    fp2.close();
        fp.close();
        remove("student.dat");
        rename("Temp.dat","student.dat");
        if(flag==1)
             cout<<"\n\n\tRecord Deleted ..";
        else
             cout<<"\n\nRecord Not Found";
        getch();
}
void delete_book()
{
    char n[6];
    cout<<"\n\n\n\tDELETE BOOK ...";
    cout<<"\n\nENTER BOOK NO THAT YOU WANT TO DELETE : ";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&bk,sizeof(book)))
    {
        if(strcmpi(bk.retbno(),n)!=0)
        {
            fp2.write((char*)&bk,sizeof(book));
        }
    }
    fp2.close();
        fp.close();
        remove("book.dat");
        rename("Temp.dat","book.dat");
        cout<<"\n\n\tRecord Deleted ..";
        getch();
}
void display_alls()
{
    fp.open("student.dat",ios::in);
    while(fp.read((char*)&st,sizeof(student)))
    {
            st.show_student();
    }
    fp.close();
}
void display_allb(treeNode *node,int lev )
{
    int i;
    if (node != NULL)
    {
        display_allb(node->right,lev+1);
        cout<<endl;
        if (node == root)
            cout<<"First->:  ";
        else
        {
            for (i = 0;i < lev;i++)
               cout<<"\t---->         ";
	    }
        cout<<node->data;
        display_allb(node->left, lev+1);
    }
}
void book_issue()
{
    char sn[6],bn[6];
    int found=0,flag=0;
    cout<<"\n\nBOOK ISSUE ...";
    cout<<"\n\n\tENTER THE STUDENT ROLL NUMBER : ";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
        fp1.open("book.dat",ios::in|ios::out);
        while(fp.read((char*)&st,sizeof(student)) && found==0)
           {
        if(strcmpi(st.retadmno(),sn)==0)
        {
            found=1;
            if(st.rettoken()==0)
            {
                cout<<"\n\n\tENTER THE BOOK NO : ";
                cin>>bn;
                while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
                {
                       if(strcmpi(bk.retbno(),bn)==0)
                    {
                        bk.show_book();
                        flag=1;
                        st.addtoken();
                        st.getstbno(bk.retbno());
                               int pos=-1*sizeof(st);
                        fp.seekp(pos,ios::cur);
                        fp.write((char*)&st,sizeof(student));
                        cout<<"\n\n\t BOOK ISSUED SUCCESSFULLY\n\nPlease Note: Write current date";
                   }
                }
                  if(flag==0)
                        cout<<"BOOK DOES NOT EXIST";
            }
                else
                  cout<<"YOU HAVE NOT RETURNED THE LAST BOOK ";
        }
    }
          if(found==0)
        cout<<"STUDENT RECORD DOES NOT EXIST...";
    getch();
      fp.close();
      fp1.close();
}
void book_deposit()
{
    char sn[6],bn[6];
    int found=0,flag=0,day,fine;
    cout<<"\n\nBOOK DEPOSIT ...";
    cout<<"\n\n\tENTER THE STUDENT'S ROLL NUMBER : ";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
       {
        if(strcmpi(st.retadmno(),sn)==0)
        {
            found=1;
            if(st.rettoken()==1)
            {
            while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
            {
               if(strcmpi(bk.retbno(),st.retstbno())==0)
            {
                bk.show_book();
                flag=1;
                cout<<"\n\nBOOK DEPOSITED IN NO.OF.DAYS : ";
                cin>>day;
                if(day>15)
                {
                   fine=(day-15)*1;
                   cout<<"\n\nFINE HAS TO BE DEPOSITED RUPEES :  "<<fine;
                }
                    st.resettoken();
                    int pos=-1*sizeof(st);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&st,sizeof(student));
                    cout<<"\n\n\t Book deposited successfully";
            }
            }
          if(flag==0)
            cout<<"BOOK NUMBER DOES NOT EXIST";
              }
         else
            cout<<"NO BOOK IS ISSUED..PLEASE CHECK!!";
        }
       }
      if(found==0)
    cout<<"STUDENT RECORD DOES NOT EXIST...";
    getch();
  fp.close();
  fp1.close();
  }
void intro()
{
    cout<<"LIBRARY  MANAGEMENT SYSTEM";
}
void admin_menu()
{
    int ch2;
    x:
    cout<<"\n\n\n\tADMINISTRATOR MENU";
    cout<<"\n\n\t1.CREATE STUDENT RECORD";
    cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORD";
    cout<<"\n\n\t3.DISPLAY SPECIFIC STUDENT RECORD ";
    cout<<"\n\n\t4.DELETE STUDENT RECORD";
    cout<<"\n\n\t5.CREATE BOOK ";
    cout<<"\n\n\t6.DISPLAY ALL BOOK ID'S ";
    cout<<"\n\n\t7.DISPLAY SPECIFIC BOOK ";
    cout<<"\n\n\t8.DELETE BOOK ";
    cout<<"\n\n\t9.BACK TO MAIN MENU";
    cout<<"\n\n\tPlease Enter Your Choice (1-9) ";
    cin>>ch2;
    if((ch2<1)&&(ch2>11))
    {
        goto x;
    }
    switch(ch2)
    {
            case 1:write_student();
                   break;
            case 2:display_alls();
                   break;
            case 3:char num[6];
                   cout<<"\n\n\tPLEASE ENTER THE ROLL NUMBER :  ";
                   cin>>num;
                   display_sps(num);
                   break;
            case 4:delete_student();
                   break;
            case 5:write_book();
                   break;
            case 6:display_allb(root,1);
                   break;
            case 7:{
                        char num[6];
                        cout<<"\n\n\tPLEASE ENTER THE BOOK NUMBER : ";
                        cin>>num;
                        display_spb(num);
                        break;
                   }
            case 8:delete_book();
                    break;
            case 9:return;
            default:cout<<"\a";
       }
       admin_menu();
}
int main()
{
    int ch;
    treeNode *root;
    intro();
    do
    {
        cout<<"\n\n\n\tMAIN MENU";
        cout<<"\n\n\t01. BOOK ISSUE";
        cout<<"\n\n\t02. BOOK DEPOSIT";
        cout<<"\n\n\t03. ADMINISTRATOR MENU";
        cout<<"\n\n\t04. EXIT";
        cout<<"\n\n\tPLEASE SELECT YOUR OPTION(1-4) ";
        cin>>ch;
        switch(ch)
        {
            case 1:book_issue();
                   break;
            case 2:book_deposit();
                   break;
            case 3:admin_menu();
                   break;
            default :cout<<"\a";
        }
    }while(ch!=4);
    return 0;
}


