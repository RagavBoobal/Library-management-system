#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include "bookis.c"
void bookissue();
void ma_section();
char st_name[20];
char st_id[20];
char book_id[20];
char book_name[20];
char name[20];
//to see book
void bsee_record()
{
FILE *fp;
int found=1;
fp=fopen("book_section.txt","r");
while(fscanf(fp,"%s %s\n",book_name,book_id)!=EOF)
{
found=0;
printf("....................\n");
printf("|  %s   |   %s      |\n",book_name,book_id);
printf("....................\n");
}
if(found!=0)
{
printf("records are empty\n");
}
fclose(fp);

}


//TO search book record
void booksearch(char nam[])
{
FILE *fp;
int found=1,res;

fp=fopen("book_section.txt","r");
while(fscanf(fp,"%s %s\n",book_name,book_id)!=EOF)
{
res=strcmp(book_id,nam);
if(res==0)
{
found=0;
printf("....................\n");
printf("|  %s   |   %s      |\n",book_name,book_id);
printf("....................\n");
} }
if(found!=0)
{
printf(" no books are found\n");
}
fclose(fp);

 }

//Insert record of book:
void binsert_record()

{
FILE *fp;
int found=1,res;
char book_name1[20],book_id1[20];
printf("Enter  book name (Space not allowed)\n");
scanf("%s",book_name);
printf("Enter book ID\n");
scanf("%s",book_id);
//fp=fopen("book_section.txt","a");
fp=fopen("book_section.txt","r");
while(fscanf(fp,"%s %s\n",book_name1,book_id1)!=EOF)
{
res=strcmp(book_id1,book_id);
if(res==0)
{
found=0;
printf("This ID has been used\n");
}
}
/*if(found==0)
{
binsert_record();
}*/
if(found!=0)
{
fp=fopen("book_section.txt","a");
fprintf(fp,"%s %s\n",book_name,book_id);
printf("record added\n");
fclose(fp);
}
fclose(fp);
}
//To delete the book record

void bdelete_record()
{

FILE *fp,*fp1;
int res,found4=1;

printf("Enter book ID\n");
scanf("%s",name);
fp=fopen("book_section.txt","r");
fp1=fopen("temp1.txt","a");
while(fscanf(fp,"%s %s\n",book_name,book_id)!=EOF)
{
res=strcmp(book_id,name);
if(res==0)
{
found4=0;
printf("name=%s\nID=%s\n",book_name,book_id);
printf("/n Is Deleted ");
}
else
{
fprintf(fp1,"%s %s\n",book_name,book_id);

}
}
if(found4!=0)
printf("not found");
fclose(fp);
fclose(fp1);

fp=fopen("book_section.txt","w");
fclose(fp);

fp=fopen("book_section.txt","a");
fp1=fopen("temp1.txt","r");

while(fscanf(fp1,"%s %s\n",book_name,book_id)!=EOF)
{
fprintf(fp,"%s %s\n",book_name,book_id);

}
fclose(fp);
fclose(fp1);
fp1=fopen("temp1.txt","w");
fclose(fp1);

}



//book section:

void book_section()
{
int a;
char c,name[20];
do
{
printf("\n");
printf(".........................\n");
printf("|  book section    |\n");
printf(".........................\n\n");

printf("\t\t\tPress <1> To see record\n");
printf("\t\t\tPress <2> To insert record\n");
printf("\t\t\tPress <3> To delete record\n");
printf("\t\t\tPress <4> To search book\n");
printf("\t\t\tPress <5> Back to Main Menu\n");
scanf("%d",&a);
switch(a)
{
case 1:
bsee_record();
break;
case 2:
binsert_record();
break;
case 3:
bdelete_record();
break;
case 4:
printf("Enter book ID\n");
scanf("%s",name);
booksearch(name);
break;
case 5:
ma_section();
break;
default:
printf("enter correct value\n");
}
fflush(stdin);
printf("Press <a> To continue with book section\n\nOR other key to main menu\n");

scanf("%c",&c);
}
while(c=='a');
}





//TO see student record
void see_record()
{
FILE *fp;
int found=1;
fp=fopen("student_section.txt","r");
while(fscanf(fp,"%s %s\n",st_name,st_id)!=EOF)
{
found=0;
printf("....................\n");
printf("|  %s   |   %s      |\n",st_name,st_id);
printf("....................\n");
}
if(found!=0)
{
printf("records are empty\n");
}
fclose(fp);

}
//to search student
void search(char nam[])
{
FILE *fp;
int found=1,res;
fp=fopen("student_section.txt","r");
while(fscanf(fp,"%s %s\n",st_name,st_id)!=EOF)
{
res=strcmp(st_id,nam);
if(res==0)
{
found=0;
printf("....................\n");
printf("|  %s   |   %s      |\n",st_name,st_id);
printf("....................\n");
}}
if(found!=0)
{
printf("records not found\n");
}
fclose(fp);

}

//Insert record of student:
void insert_record()

{
FILE *fp;
char ch,st_name1[20],st_id1[20];
int found=1,res;


//fp=fopen("student_section.txt","a");
printf("Enter student name (Space not allowed)\n");
scanf("%s",st_name);
printf("Enter student ID\n");
scanf("%s",st_id);

fp=fopen("student_section.txt","r");
while(fscanf(fp,"%s %s\n",st_name1,st_id1)!=EOF)
{
res=strcmp(st_id1,st_id);
if(res==0)
{
found=0;
printf("This ID has been used\n");
}
}
/*if(found==0)
{
insert_record();
} */
if(found!=0)
{
fp=fopen("student_section.txt","a");
fprintf(fp,"%s %s\n",st_name,st_id);
printf("record added\n");
fclose(fp);
}
fclose(fp);
}



//To delete the student record

void delete_record(char na[])
{
int res,found4=1;
FILE *fp,*fp1;
fp=fopen("student_record.txt","r");
fp1=fopen("temp.txt","a");
while(fscanf(fp,"%s %s\n",st_name,st_id)!=EOF)
{
res=strcmp(st_id,na);
if(res==0)
{
found4=0;
printf("name=%s\nID=%s\n",st_name,st_id);
printf("/n Is Deleted ");
}
else
{
fprintf(fp1,"%s %s\n",st_name,st_id);

}
}

if(found4!=0)
printf("not found");
fclose(fp);
fclose(fp1);

fp=fopen("student_section.txt","w");
fclose(fp);

fp=fopen("student_section.txt","a");
fp1=fopen("temp.txt","r");

while(fscanf(fp1,"%s %s\n",st_name,st_id)!=EOF)
{
fprintf(fp,"%s %s\n",st_name,st_id);

}
fclose(fp);
fclose(fp1);
fp1=fopen("temp.txt","w");
fclose(fp1);


}



//Student section:

void student_section()
{
int a;
char c,nam[20];
do
{
char name[20];

printf("\n");
printf(".........................\n");
printf("|  student section    |\n");
printf(".........................\n\n");

printf("\t\t\tPress <1> To see record\n");
printf("\t\t\tPress <2> To insert record\n");
printf("\t\t\tPress <3> To delete record\n");
printf("\t\t\tPress <4> To search Student\n");
printf("\t\t\tPress <5> Back to main menu\n");
scanf("%d",&a);
switch(a)
{
case 1:
see_record();
break;
case 2:
insert_record();
break;
case 3:
printf("Enter student ID\n");
scanf("%s",nam);
delete_record(nam);
break;
case 4:
printf("Enter student ID\n");
scanf("%s",name);
search(name);
break;
case 5:
ma_section();
break;
default:
printf("enter correct value\n");
}
fflush(stdin);
printf("Press <a> To continue with student section\n");
scanf("%c",&c);
}
while(c=='a');
}


void ma_section()
{
int n;
char ch;
do
{
printf("\t\t\t.........................\n");
printf("\t\t\t|  LIBRARY MANAGEMENT    |\n");
printf("\t\t\t.........................\n");
printf("\nPress<1> For Student section\nPress<2> For Book section\nPress<3> For Book issue section\n<press<4> To exit\n");
scanf("%d",&n);
switch(n)
{
case 1:
student_section();
break;
case 2:
book_section();
break;
case 3:
bookissue();
break;
case 4:
exit(0);
default:
printf("please enter correct choice\n");
}
printf("For main menu press any key\n");
scanf("%c",&ch);
}
while(ch!='-');
}
void bookissue()
{
int m;
char ch1;
do
{
printf("\t\t\t.........................\n");
printf("\t\t\t|  LIBRARY MANAGEMENT    |\n");
printf("\t\t\t.........................\n");
printf("Press <1> To book Issue\nPress <2>To submit Book\nPress <3> To check no Dues\nPress <4> key to Back\n");
scanf("%d",&m);
switch(m)
{
case 1:
book_issue();
break;
case 2:
book_submit();
break;
case 3:
nodues();

break;
case 4:
ma_section();
break;
default:
printf("error");
}
fflush(stdin);
printf("\npress <a> To continue in same section\n");
scanf("%c",&ch1);
}
while(ch1=='a');
}
