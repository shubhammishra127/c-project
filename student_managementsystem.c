/*
===========================================
 Project Name : Student Management System
 Language     : C
 Author       : Shubham Mishra
 Description  : Console based C project using
                file handling to manage
                student records.
===========================================
*/

#include<stdio.h>
#include<string.h>

// structure defination
struct student{
    int rollno;
    char name[50];
    char mobile_no[11];
    float marks;
};

//global array and counter
struct student s[50];
int count = 0;
    

// This function is used to add student details
void addStudent(){
   FILE *fp;
   fp = fopen("Students.txt", "a");
   if( fp == NULL){
    printf("file not found!\n");
    return;
   }

    printf("\nEnter rollno: ");
    scanf("%d", &s[count].rollno);
    getchar();

    printf("\nEnter name: ");
    fgets(s[count].name, 50, stdin);
    s[count].name[strcspn(s[count].name, "\n")] = '\0';

    
    printf("Enter mobile no (10 digits): ");
    scanf("%10s", s[count].mobile_no);
    getchar();   // clear enter


    printf("\nEnter marks: ");
    scanf("%f", &s[count].marks);
    getchar();

    fprintf(fp, "%d %s %s %.2f\n",s[count].rollno,s[count].name,s[count].mobile_no,s[count].marks);
    fclose(fp);

    count++;

    printf("\nStudent added & saved succesfully!");
}
// This function is used to display student details
void displayFromfile(){
   FILE *fp;
   struct student temp;

   fp = fopen("Students.txt", "r");
   if( fp == NULL){
    printf("Record not found!\n");
    return;
   }
    
    printf("\n ------ Student List ------ \n");

    while(fscanf(fp,"%d %s %s %f\n", &temp.rollno,temp.name,temp.mobile_no,&temp.marks) != EOF){
        printf("\n Roll NO : %d", temp.rollno);
        printf("\n Name : %s", temp.name);
        printf("\n Mobile No : %s", temp.mobile_no);
        printf("\n Marks : %.2f", temp.marks);
        printf("\n");
    }
    fclose(fp);
    

}
// This function is used to search student details
void searchFromfile(){
    FILE *fp;
    struct student temp;
    int r, found = 0;

    fp = fopen("Students.txt", "r");
   if( fp == NULL){
    printf("Record not found!\n");
    return;
   }

    printf("\nEnter rollno no to search: ");
    scanf("%d", &r);

    
    while(fscanf(fp,"%d %s %s %.2f", &temp.rollno,&temp.name,&temp.mobile_no,&temp.marks) != EOF){
            if(temp.rollno == r){
               printf("\nStudent Found!"); 
               printf("\n Roll NO : %d", temp.rollno);
               printf("\n Name : %s", temp.name);
               printf("\n Mobile No : %s", temp.mobile_no);
               printf("\n Marks : %.2f", temp.marks);
               found = 1;
               break;
            }
        }
    
    
    if(found == 0){
        printf("\nStudent Not Found!");   
    }
    fclose(fp);

}
void countstudents(){
    FILE *fp;
    struct student s;
    int count = 0;

    fp = fopen("Students.txt", "r");
    if (fp == NULL) {
        printf("\nNo records found!");
        return;
    }

    while (fscanf(fp, "%d %s %s %f",
                  &s.rollno, s.name, s.mobile_no, &s.marks) != EOF) {
        count++;
    }

    fclose(fp);
    printf("\nTotal Students: %d\n", count);
}
int main(){
    int choice;
     while(1) {
        printf("\n----- Student Management System -----");
        printf("\n1. Add Students");
        printf("\n2. Display Students");
        printf("\n3. Search Students");
        printf("\n4. Total students");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent();
                break;
            
            case 2:
                displayFromfile();   
                break; 
            case 3:
                searchFromfile();
                break;
            case 4:
                countstudents();
                break;         

            case 5:
                printf("Program Exit");
                return 0;

            default:
                printf("Invalid Choice");
        }
    }
}
