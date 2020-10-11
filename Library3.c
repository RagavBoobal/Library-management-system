#include<stdio.h>
#include<conio.h>
#include<string.h>

using namespace std;
//#include"library1.h"
//void bookissue();
//void book_issue();
char date[20];
char st_name[20],st_id[20],book_name[20],book_id[20];
char sid[20],bid[20];


void book_issue()
{
FILE *fp,*fp1,*fp2;
int res,res1,found=1,found1=1;

char name1[20];
printf("enter Student ID\n");
scanf("%s",sid);
fp=fopen("student_section.txt","r");
while(fscanf(fp,"%s %s\n",st_name,st_id)!=EOF)
{
res1=strcmp(st_id,sid);
if(res1==0)
{
found=0;
printf("Name: %s\nSt. ID: %s",st_name,st_id);
printf("\nEnter book ID to be issued\n");
scanf("%s",bid);
fp=fopen("book_section.txt","r");
while(fscanf(fp,"%s %s\n",book_name,book_id)!=EOF)
{
res=strcmp(book_id,bid);
if(res==0)
{
found1=0;
printf("Enter Date (dd-mm-yy)\n");
scanf("%s",date);
printf("Book with ID %s \n name: %s \nis issued",book_id,book_name);
fp2=fopen("book_issue.txt","a");
fprintf(fp2,"%s %s %s %s %s\n",st_name,st_id,book_name,book_id,date);
}
}
if(found1!=0)
{
printf("No book found\n");
}
}

}
if(found!=0)
{
printf("No Student found with this ID\n");
}
fclose(fp);
fclose(fp2);
}


void book_submit()
{
FILE *fp2,*fp1;
int p,o,res2,found2=1,res;
char stid[20],boid[20];

printf("Press <1> To submit  book by Student Id\nPress <2> To submit by Book ID\n");
scanf("%d",&o);
switch(o)
{
case 1:

printf("Enter student ID\n");
scanf("%s",stid);
fp2=fopen("book_issue.txt","r");
while(fscanf(fp2,"%s %s %s %s %s\n",st_name,st_id,book_name,book_id,date)!=EOF)
{
res2=strcmp(st_id,stid);
if(res2==0)
{
  found2=0;
  printf("Book name:%s \nBook:%s \nDate:%s\n",book_name,book_id,date);
  printf("book submitted\n");


fp1=fopen("temp.txt","a");
while(fscanf(fp2,"%s %s %s %s %s\n",st_name,st_id,book_name,book_id,date)!=EOF)
{
res=strcmp(st_id,stid);
if(res==0)
{

}
else
{
fprintf(fp1,"%s %s %s %s %s\n",st_name,st_id,book_name,book_id,date);

}
}
fclose(fp2);
fclose(fp1);

fp2=fopen("book_issue.txt","w");
fclose(fp2);

fp2=fopen("book_issue.txt","a");
fp1=fopen("temp.txt","r");
//fprintf(fp1,"%s %s\n",name,roll);
while(fscanf(fp1,"%s %s %s %s %s\n",st_name,st_id,book_name,book_id,date)!=EOF)
{
//fscanf(fp1,"%s %s\n",name,roll);
fprintf(fp2,"%s %s %s %s %s\n",st_name,st_id,book_name,book_id,date);

}
fclose(fp2);
fclose(fp1);
fp1=fopen("temp.txt","w");
fclose(fp1);
fclose(fp2);
}
}
if(found2!=0)
{
printf("No book has issued to this ID");
}
break;

case 2:

printf("Enter Book ID\n");
scanf("%s",boid);
fp2=fopen("book_issue.txt","r");
while(fscanf(fp2,"%s %s %s %s %s\n",st_name,st_id,book_name,book_id,date)!=EOF)
{
res2=strcmp(book_id,boid);
if(res2==0)
{
  found2=0;
  printf("student name:%s \nId:%s \nDate:%s\n",st_name,st_id,date);
  printf("book submitted\n");

  fp2=fopen("book_issue.txt","r");
fp1=fopen("temp.txt","a");
while(fscanf(fp2,"%s %s %s %s %s\n",st_name,st_id,book_name,book_id,date)!=EOF)
{
res=strcmp(book_id,boid);
if(res==0)
{

}
else
{
fprintf(fp1,"%s %s %s %s %s\n",st_name,st_id,book_name,book_id,date);

}
}
fclose(fp2);
fclose(fp1);

fp2=fopen("book_issue.txt","w");
fclose(fp2);

fp2=fopen("book_issue.txt","a");
fp1=fopen("temp.txt","r");
//fprintf(fp1,"%s %s\n",name,roll);
while(fscanf(fp1,"%s %s %s %s %s\n",st_name,st_id,book_name,book_id,date)!=EOF)
{
//fscanf(fp1,"%s %s\n",name,roll);
fprintf(fp2,"%s %s %s %s %s\n",st_name,st_id,book_name,book_id,date);

}
fclose(fp2);
fclose(fp1);
fp1=fopen("temp.txt","w");
fclose(fp1);
fclose(fp2);
}
}
if(found2!=0)
{
printf("No book has issued to this ID");
}
break;

default:
printf("please choose correct option\n");
}


}

void nodues()
{
FILE *fp2,*fp;
int res2,found2=1,found1=1,res1;
char stid1[20],name3[20];
printf("Enter student ID\n");
scanf("%s",stid1);
fp2=fopen("book_issue.txt","r");
while(fscanf(fp2,"%s %s %s %s %s\n",st_name,st_id,book_name,book_id,date)!=EOF)
{
res2=strcmp(st_id,stid1);
if(res2==0)
{
found2=0;
printf("Student have not submitted the book\n");
printf("\n Book details\n Name: %s\n ID: %s\n",book_name,book_id);
}
}
if(found2!=0)
{
fp=fopen("student_section.txt","r");
while(fscanf(fp,"%s %s\n",st_name,st_id)!=EOF)
{
res1=strcmp(st_id,stid1);
if(res1==0)
{
found1=0;
printf("student name: %s\nstudent ID: %s\n",st_name,st_id);
printf("NO DUES\n");
}
}
}
fclose(fp);
if(found1!=0)
{
printf("Not found\n");
}
fclose(fp2);

}

