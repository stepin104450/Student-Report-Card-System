#include<stdio.h>
#include<process.h>
#include<windows.h>
struct student
{
 int rollno;
 int total;
 char name[50];
 int m_marks,a_marks,e_marks,d_marks,p_marks;
 float per;
 char status;
 int std;
}st;
 FILE *fptr;

 /*TO CREATE THE DATABASE FOR MARKS OF THE STUDENTS*/

void write_student()
   {
    fptr=fopen("student.dat","ab");
    printf("\nPlease Enter The New Details of student \n");
    printf("\nEnter The roll number of student ");
    scanf("%d",&st.rollno);
    fflush(stdin);
    printf("\n\nEnter The Name of student ");
    gets(st.name);
    printf("\nEnter The marks in MPDSP marks out of 100 : ");
    scanf("%d",&st.m_marks);
    printf("\nEnter The marks in ACN marks out of 100 : ");
    scanf("%d",&st.a_marks);
    printf("\nEnter The marks in ESD marks out of 100 : ");
    scanf("%d",&st.e_marks);
    printf("\nEnter The marks in DIVP marks out of 100 : ");
    scanf("%d",&st.d_marks);
    printf("\nEnter The marks in PROJECT marks out of 100 : ");
    scanf("%d",&st.p_marks);
    st.total= (st.m_marks+st.a_marks+st.e_marks+st.d_marks+st.p_marks);
    st.per=(st.m_marks+st.a_marks+st.e_marks+st.d_marks+st.p_marks)/5.0;
    if(st.per>=60)
       st.status='P';
    else if(st.per>=50 &&st.per<60)
      st.status='P';
    else if(st.per>=33 &&st.per<50)
      st.status='P';
    else
     st.status='F';
    fwrite(&st,sizeof(st),1,fptr);
    fclose(fptr);
    printf("\n\nStudent Record Has Been Created ");
    getch();
}

/* TO DISPLAY ALL THE MARKS OF THE STUDENT */

void display_all()
{
    system ("cls");
    printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");
    fptr=fopen("student.dat","rb");
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
      printf("\nRoll Number of Student : %d",st.rollno);
      printf("\nName of student : %s",st.name);
      printf("\nMarks in MPDSP : %d",st.m_marks);
      printf("\nMarks in ACN : %d",st.a_marks);
      printf("\nMarks in ESD : %d",st.e_marks);
      printf("\nMarks in DIVP : %d",st.d_marks);
      printf("\nMarks in Project : %d",st.p_marks);
      printf("\nTotal marks of student is : %d",st.total);
      printf("\nPercentage of student is  : %.2f",st.per);
      printf("\nStatus of student is : %c",st.status);
      printf("\n\n====================================\n");
      getch();
    }
    fclose(fptr);
    getch();
}



void display_sp(int n)
{
    int flag=0;
    fptr=fopen("student.dat","rb");
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
     if(st.rollno==n)
        {
         system ("cls");
            printf("\nRoll number of student : %d",st.rollno);
            printf("\nName of student : %s",st.name);
            printf("\nMarks in MPDSP : %d",st.m_marks);a
            printf("\nMarks in ACN : %d",st.a_marks);
            printf("\nMarks in ESD : %d",st.e_marks);
            printf("\nMarks in DIVP : %d",st.d_marks);
            printf("\nMarks in Project : %d",st.p_marks);
            printf("\nTotal marks of student is : %d",st.total);
            printf("\nPercentage of student is  : %.2f",st.per);
            printf("\nStatus of student is : %c",st.status);
         flag=1;
        }
    }
    fclose(fptr);
if(flag==0)
 printf("\n\nrecord not exist");
    getch();
}



void modify_student()
{
    int no,found=0;
    system ("cls");
    printf("\n\n\tTo Modify ");
    printf("\n\n\tPlease Enter The roll number of student");
    scanf("%d",&no);
    fptr=fopen("student.dat","rb+");
    while((fread(&st,sizeof(st),1,fptr))>0 && found==0)
    {
    if(st.rollno==no)
           {
            printf("\nRoll number of student : %d",st.rollno);
            printf("\nName of student : %s",st.name);
            printf("\nMarks in MPDSP : %d",st.m_marks);
            printf("\nMarks in ACN : %d",st.a_marks);
            printf("\nMarks in ESD : %d",st.e_marks);
            printf("\nMarks in DIVP : %d",st.d_marks);
            printf("\nMarks in Project : %d",st.p_marks);
            printf("\nTotal marks of student is : %d",st.total);
            printf("\nPercentage of student is  : %.2f",st.per);
            printf("\nStatus of student is : %c",st.status);
            printf("\nPlease Enter The New Details of student \n");
            printf("\nEnter The roll number of student ");
            scanf("%d",&st.rollno);
            fflush(stdin);
            printf("\n\nEnter The Name of student ");
            gets(st.name);
            printf("\nEnter The marks in MPDSP out of 100 : ");
            scanf("%d",&st.m_marks);
            printf("\nEnter The marks in ACN out of 100 : ");
            scanf("%d",&st.a_marks);
            printf("\nEnter The marks in ESD out of 100 : ");
            scanf("%d",&st.e_marks);
            printf("\nEnter The marks in DIVP out of 100 : ");
            scanf("%d",&st.d_marks);
            printf("\nEnter The marks in Project out of 100 : ");
            scanf("%d",&st.p_marks);
            st.total= (st.m_marks+st.a_marks+st.e_marks+st.d_marks+st.p_marks);
            st.per=(st.m_marks+st.a_marks+st.e_marks+st.d_marks+st.p_marks)/5.0;
            if(st.per>=60)
               st.status='P';
            else if(st.per>=50 && st.per<60)
               st.status='P';
            else if(st.per>=33 && st.per<50)
               st.status='P';
            else
               st.status='F';
            fseek(fptr,-(long)sizeof(st),1);
            fwrite(&st,sizeof(st),1,fptr);
            printf("\n\n\t Record Updated");
            found=1;
           }
         }
    fclose(fptr);
    if(found==0)
    printf("\n\n Record Not Found ");
    getch();
}





void delete_student()
   {
    int no;
    FILE *fptr2;
    system ("cls");
    printf("\n\n\n\tDelete Record");
    printf("\n\nPlease Enter The roll number of student You Want To Delete");
    scanf("%d",&no);
    fptr=fopen("student.dat","rb");

    fptr2=fopen("Temp.dat","wb");
    rewind(fptr);
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
       if(st.rollno!=no)
       {
      fwrite(&st,sizeof(st),1,fptr2);
       }
    }
    fclose(fptr2);
    fclose(fptr);
    remove("student.dat");
    rename("Temp.dat","student.dat");
    printf("\n\n\tRecord Deleted ..");
    getch();
}



    void class_result()
    {
     system ("cls");
     fptr=fopen("student.dat","rb");
     if(fptr==NULL)
     {
       printf("ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File");
       printf("\n\n\n Program is closing ....");
       getch();
       exit(0);
     }

     printf("\n\n\t\tALL STUDENTS RESULT \n\n");
      printf("============================================================================================================================\n");
      printf("R.No.  Name     MPDSP(100)   ACN(100)   ESD(100)   DIP(100)   PROJECT(100)  Total(500)  Percentage     Status(Pass-P/Fail-F)\n");
      printf("============================================================================================================================\n");

      while((fread(&st,sizeof(st),1,fptr))>0)
     {
       printf("%-6d %-10s      %-3d         %-3d       %-3d       %-3d        %-3d        %-3d         %-3.2f          %-1c\n",st.rollno,st.name,st.m_marks,st.a_marks,st.e_marks,st.d_marks,st.p_marks,st.total,st.per,st.status);
     }
     fclose(fptr);
     getch();
}



   void result()
   {
    int ans,rno;
    char ch;
    system ("cls");
    printf("\n\n\nRESULT MENU");
    printf("\n\n\n1. Class Result\n\n2. Student Report Card\n\n3.Back to Main Menu");
    printf("\n\n\nEnter Choice (1/2)? ");
    scanf("%d",&ans);
    switch(ans)
    {
     case 1 : class_result();break;
     case 2 : {
        do{
        char ans;
        system ("cls");
        printf("\n\nEnter Roll Number Of Student : ");
        scanf("%d",&rno);
        display_sp(rno);
        printf("\n\nDo you want to See More Result (y/n)?");
        scanf("%c",&ans);
        }while(ans=='y'||ans=='Y');
        break;
           }
     case 3: break;
     default:  printf("\a");
    }
 }

void gotoxy(int a, int b)
    {
        COORD c;

        c.X=a;
        c.Y=b;

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    }

void intro()
{
 system ("cls");
 gotoxy(35,11);
 printf("STUDENT");
 gotoxy(33,14);
 printf("REPORT CARD");
 gotoxy(35,17);
 printf("SYSTEM");
 printf("\n\n\n\n\n\nBY : G.Srinidhi");
 printf("\n\nStepin_ID:104450");
 getch();
}

void entry_menu()
{
    char ch2;
  system ("cls");
  printf("\n\n\n\tENTRY MENU");
  printf("\n\n\t1.CREATE STUDENT MARKS RECORD");
  printf("\n\n\t2.DISPLAY ALL STUDENT MARKS RECORDS");
  printf("\n\n\t3.SEARCH STUDENT MARKS RECORD ");
  printf("\n\n\t4.MODIFY STUDENT MARKS RECORD");
  printf("\n\n\t5.DELETE STUDENT MARKS RECORD");
  printf("\n\n\t6.BACK TO MAIN MENU");
  printf("\n\n\tPlease Enter Your Choice (1-6) ");
  ch2=getche();
  switch(ch2)
  {
    case '1': system ("cls");
          write_student();
          break;
    case '2': display_all();break;
    case '3':  {
           int num;
           system ("cls");
           printf("\n\n\tPlease Enter The roll number ");
           scanf("%d",&num);
           display_sp(num);
           }
           break;
      case '4': modify_student();break;
      case '5': delete_student();break;
      case '6': break;
      default:printf("\a");entry_menu();
   }
}
void main()
{
  char ch;
  intro();
  do
    {
      system ("cls");
      printf("\n\n\n\tMAIN MENU");
      printf("\n\n\t01. RESULT MENU");
      printf("\n\n\t02. ENTRY/EDIT MENU");
      printf("\n\n\t03. EXIT");
      printf("\n\n\tPlease Select Your Option (1-3) ");
      ch=getche();
      switch(ch)
      {
         case '1': system ("cls");
               result();
               break;
          case '2': entry_menu();
                break;
          case '3':exit(0);
          default :printf("\a");
    }
    }while(ch!='3');
}
