#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void change_name();
int BUFFER_CLEANER();
int CREATE_BACKUP();
void LOWER_CASE(string input);
void ADMIN();
void ls();
int ADD_STUDENT();
void change_grade();
void grades(int x);
void info();
const char* check_pass(int y);
void delete();
int AVRAGE();
int grades_LIST(int x);
int SEARCH();

typedef char *string;
struct STUDENT_DATA{
    int id[20];
    char name[20][30];
    float grade[20][5];
    float avrage[20];
}Data;

int student_count=0;

int main(void){
    int dec;
    while(true){
    printf(" Simple Grade System for Students \n");
    printf("--------------------------------------------------\n");
    printf("1. Add Student information & Grades\n");
    printf("2. Calculate Average for students\n");
    printf("3. Display Students Info By ID\n");
    printf("4. ADMIN panel\n");
    printf("5. exit\n");
    printf("---------------------------------------------------\n ");
    printf("Enter your Choice: (a number from 1 to 5) ");
    scanf("%d",&dec);
    switch (dec)
    {
    case 1:
        
        ADD_STUDENT();
        break;
    case 2:
        AVRAGE();
        printf("all students mark has been avraged");
        break;

    case 3:
        SEARCH();
        break;
    case 4:
        admin();
        break;
    case 5:
        return 0;
    default:
        printf("invalid input");    
                

    }
}
}
int ADD_STUDENT(){
    int ID_BUFF;
    bool ID=true;
    do
    {   
        ID=true;
        printf("please first enter your id to verify \n");
        scanf("%d",&ID_BUFF);
        if (ID_BUFF>999999 || ID_BUFF<100000)
        {
            printf("invalid ID (it has to be 6 digit )\n");
            continue;
        }
        
        for (int i = 0; i < student_count; i++)
        {
            if (ID_BUFF==Data.id[i])
            {
                printf("id is already taken!!!\n");
                ID=false;
            }
           
        }
        if (ID==true)
        {
            break;
        }
        
    } while (true);
    Data.id[student_count]=ID_BUFF;



    char Name[30];
    printf("please enter your name and nikname  \n");
    scanf(" %[^\n]", Name);
    LOWER_CASE(Name);
    strcpy(Data.name[student_count],Name);
    printf("welcome  mr/ms  %s,to fulfill our data pleas enter your marks for the semester\n",Name);
    for (int j = 0; j < 5; j++)
    {
        printf("%d. ",j+1);
        scanf("%f",&Data.grade[student_count][j]);
        if ((Data.grade[student_count][j])<0.0 || (Data.grade[student_count][j])>20.0)//not sure about the op 
        {
            printf("invalid mark!!!!!\n");
            j--;     
        }   
    }
    student_count++;
    }
int AVRAGE(){
    for (int i = 0; i < student_count; i++)
    {
        float  sum=0;
        for (int j = 0; j <5; j++)
        {
            sum+=Data.grade[i][j];
        }
        Data.avrage[i]=sum/5;
        
    }
    
}
int grades_LIST(int x){
    for (int i = 0; i < 5; i++)
    {
        printf("%d. %f\n",i+1,Data.grade[x][i]);
    }
    return 0;
    

}
int SEARCH(){
    char conts;
    bool found=false;
    int found_std;
    int tmp;
    printf("please enter studnets id to search for its info\n");
    scanf("%d",&tmp);
    for (int i = 0; i <student_count; i++)
    {
        if (Data.id[i]==tmp)
        {
            found_std=i;
            found=true;  
        }
        
    
    }
    if (found)
    {
        printf("the student you are looking for is mr/ms %s\n",Data.name[found_std]);
        printf("grades: \n");
        grades_LIST(found_std);
        AVRAGE();
        printf("Avrage: %.3f\n",Data.avrage[found_std]);
        
    }
    else {
        printf("there is no student with %d id\n",tmp);
        printf("do you want to try another id (y,n)");
        BUFFER_CLEANER();

        scanf("%c",&conts);
        if (conts=='y')
        {
            SEARCH();
        }
        else
        {
            return 0;
        }
    }
    
}    
  
int BUFFER_CLEANER(){
    while (getchar() !='\n');//خالی کردن بافر های اضافه در ترمینال 
    
}
int CREATE_BACKUP(){
    FILE *backup_todo;
    string buffer;
    BUFFER_CLEANER();
    char c;
    printf("give me a directry for a new folder (txt)(use double\\ to use back slash notation):\n");
    scanf("%s",buffer);
    BUFFER_CLEANER();
    backup_todo=fopen(buffer,"w");//ساختن فایل برای نوشتن
    if (backup_todo==NULL)
    {
        printf("couldnt allocate the folder please try again !!!!\n");//چک کردن ادرس درست
        return 1;
    }
    fprintf(backup_todo,"======STUDENTS LIST=======\n");
    for (int i = 0; i < student_count; i++)
    {
        fprintf(backup_todo,"student id: %s\n",Data.id[i]);
        fprintf(backup_todo,"student name: %s\n",Data.name[i]);
        fprintf(backup_todo,"student mark:\n");
        for (int j = 0; j < 5; j++)
        {
            fprintf(backup_todo,"%d. %f\n",j+1,Data.grade[i][j]);
        }
        AVRAGE();
        fprintf(backup_todo,"student avrage:%f",Data.avrage[i]);
    }
        

    printf("backup has been created in this location:%s\n",buffer);//لوپ برای اضافه کردن کل تسک های انجام شده به تکست
    fclose(backup_todo);
    
}
void LOWER_CASE(string input){
    for (int i = 0; input[i]!='\0'; i++)
    {
        if (input[i]>='A' &&input[i]<='Z')//کوچک کردن حروف با کمک بیت 
        {
            input[i]+=32;
        }
        
    }
    

} 

void ADMIN(){
    int admin_input;
    printf("welcome to admin panel!!!\n");
    while(admin_input!=4){
        printf("choose one of there option below:\n");
        printf("1.chnage student info\n");
        printf("2.change student grade\n");
        printf("3.information of all students\n ");
        printf("4.delete student from the list\n");
        printf("5.take backup from students info and grade\n");
        printf("6.exit\n");
        scanf("%d",&admin_input);
        BUFFER_CLEANER();
        switch (admin_input)
        {
        case 1:
            change_name();
            continue;
        case 2:
            change_grade();
            ADMIN();

        case 3:
        info();
        ADMIN();
        
        case 4:
        delete();
        ADMIN();

        case 5:
        CREATE_BACKUP();
        ADMIN();
        
        case 6:
        printf("exiting from teacher panel....\n");
        return;
        
        }
    }

}
void ls(){
    printf("-----------STUDENT LIST---------\n");
    for(int i=0;i<student_count;i++){

        printf("%d.%s with id:%s\n",i+1,Data.name[i],Data.id[i]);

    }
    printf("-------------------------------\n");
}


void change_name(){
    int index;
    int buff;
    char new_name[30];
    
    if(student_count == 0) {
        printf("No students found!!!!\n");
        return;
    }
    ls();
    printf("choose one of the student to change its info");
    scanf("%d",&buff);
    BUFFER_CLEANER();

    index=buff-1;

    if(index < 0 || index >= student_count) {
        printf("Invalid !\n");
        return;
    }    
    printf("the student you chose is %s",Data.name[index]);
    printf("enter new name or info for the student\n");
    scanf(" %[^\n]", new_name);
    BUFFER_CLEANER();
    LOWER_CASE(new_name);
    strcpy(Data.name[index],new_name);
    printf("student number %d changed to %s with id:%d\n",buff,Data.name[index],Data.id[index]);
    return;

}

void change_grade(){
    int new_grade;
    int input;
    int buff;
    printf("choose on of students to change their grades :\n");
    ls();
    scanf("%d",&buff);
    BUFFER_CLEANER();

        buff--;
        
        printf("grades for studen :%s\n",Data.name[buff]);
        grades(buff);
        avrage();
        printf("avrage : %f",Data.avrage[buff]);
        printf("6.exit");
        printf("choose on option\n");
        scanf("%d",&input);
        if (input==6)
        {
            return;
        }
        printf("what do you want to replace with(0,20) :");
        scanf("%d",&new_grade);
        BUFFER_CLEANER();
        if(new_grade >= 0 && new_grade <= 20) {
        Data.grade[buff][input-1] = new_grade;
        printf("new grade has been changed!\n");
        AVRAGE();  
        printf("New grades:\n");
        grades(buff);
        printf("New average: %.2f\n", Data.avrage[buff]);
    } else {
        printf("Invalid grade!\n");
    
    }        
    change_grade();

}
void grades(int x){
    for (int i = 0; i < 5; i++)
    {
        printf("%d.%f\n",i+1,Data.grade[x][i]);
    }
    

}
void info(){
    printf("===================all student=======\n");
    for (int i = 0; i < student_count; i++)
    {
        printf("%d---------\n",i+1);
        printf("name:%s\n",Data.name[i]);
        printf("id: %d\n",Data.id[i]);
        printf("grades :\n");
        grades(i);
        AVRAGE();
        printf("Average: %.2f\n", Data.avrage[i]);
        printf("studen status: %s\n",check_pass(i));
        printf("--------------------------------\n");
      

    }
    
}
const char* check_pass(int y){
    AVRAGE();
    if (Data.avrage[y]>=10)
    {
        return "pass";
    }
    return "fail";

}


void delete(){
int index;
    ls();
printf("choose an student to delete !!!\n");
scanf("%d",&index);
index--;
    for (int i = index; i < student_count - 1; i++) {
        Data.id[i] = Data.id[i+1];
        strcpy(Data.name[i], Data.name[i+1]);
        Data.avrage[i] = Data.avrage[i+1];
        for(int j = 0; j < 5; j++) {
            Data.grade[i][j] = Data.grade[i+1][j];
        }
    }
    student_count--;
    printf("Student deleted successfully!\n");



}

  



    
