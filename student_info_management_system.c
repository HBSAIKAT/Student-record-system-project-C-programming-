#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#define ll long long int
struct student
{
    ll id;
    char name[30], section[2], semester[10], department[50], blood_group[5];
    char college_name[50], hsc_board[20], school_name[30], ssc_board[20];
    int hsc_year, ssc_year;
    float hsc_result, ssc_result;
    ll phone, f_phone, m_phone;
    char f_name[30], m_name[30];
    char guardian[30], pre_address[30], per_address[30], others[100];
};
struct password
{
    char username[30];
    char password[30];
};
struct student stu;
struct password p;
void introduction(void);
void menu(void);
void getchoice(void);
void add_student(void);
int get_password(int check);
int password_conf(char temp_use[], char temp_pass[]);
int conf_record(ll s_id);
void search_student(void);
void modify_record(void);
void delete_record(void);
void change_password(void);
int old_password_check(int check);
char old_username[100];
void cls()
{
    system("cls");
}

int main()
{
    system("color A");

    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t|____________________|\n\t\t\t\t\t|                    |\n\t\t\t\t\t|\tWelcome      |\n\t\t\t\t\t|____________________|\n\t\t\t\t\t|\t\t     |\n\n\n");
    printf("Enter any key from keyboard to continue.\n");
    getch();
    cls();


    introduction();
    menu();
    getchoice();
    return 0;
}
void introduction(void)
{
    cls();
    for(int i=0; i<=100; i++)
        printf("-");
    printf("\n");
    printf("\t\tSTUDENT RECORD SYSTEM FOR DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING\n");
    printf("\t\t\t\tPremier University, Chittagong, Bangladesh\n");
    printf("\t\t\t\t\t\tEstd. : 2004\n");
    for(int i=0; i<=100; i++)
        printf("-");
    printf("\n");
}
void menu(void)
{
    printf("\n\n");
    printf("1. Add Student\n\n");
    printf("2. Search Student\n\n");
    printf("3. Modify Student Record\n\n");
    printf("4. Delete Student Record\n\n");
    printf("5. Change Password for Admin\n\n");
    printf("6. Exit\n\n");
}
void getchoice(void)
{
    //system("color B");
    int c;
    printf("\n\n\n");
    printf("Enter your choice: ");
    scanf("%d", &c);
    switch(c)
    {
    case 1:
        add_student();
        break;
    case 2:
        search_student();
        break;
    case 3:
        modify_record();
        break;
    case 4:
        delete_record();
        break;
    case 5:
        change_password();
        break;
    case 6:
        exit(0);
        break;
    default:printf("\n\n\n\n\n\n\n\t\t\t\tInvalid input!!!");
            printf("\n\t\t\tPlease Enter Correct Key to Access.");
            printf("\n\t\t\t\tOr Enter 6 to Exit.\n");
            menu();
            getchoice();

    }
}
void add_student(void)
{
    //system("color E");
    cls();
    FILE *fp;

    int check=1;

    get_password(check);

    fp = fopen("record.txt", "a");//ab+
    printf("\n\n\t\t\tStudent's Details\n");
    printf("\t\t_________________________________\n");

    printf("ID:   "); scanf("%lld", &stu.id);
    ll s_id = stu.id;
    if(conf_record(s_id))
    {
        stu.id = s_id;
        printf("Name: "); getchar(); gets(stu.name);
        printf("Section: "); gets(stu.section);
        printf("Semester: "); gets(stu.semester);
        printf("Department: "); gets(stu.department);
        printf("Student Blood Group: "); gets(stu.blood_group);

        printf("\n\n\n\t\t\tStudent's Background\n");
        printf("\t\t____________________________________\n");

        printf("College Name: "); gets(stu.college_name);
        printf("H.S.C passing year: "); scanf("%d", &stu.hsc_year);
        printf("H.S.C Result in GPA: "); scanf("%f", &stu.hsc_result);
        printf("H.S.C Board: "); getchar(); gets(stu.hsc_board);
        printf("\n\n");
        printf("School Name: "); gets(stu.school_name);
        printf("S.S.C passing year: "); scanf("%d", &stu.ssc_year);
        printf("S.S.C Result in GPA: "); scanf("%f", &stu.ssc_result);
        printf("S.S.C Board: "); getchar(); gets(stu.ssc_board);

        printf("\n\n\n\t\t\tStudent's Contract Information\n");
        printf("\t\t_____________________________________________\n");

        printf("Student's mobile number: "); scanf("%lld", &stu.phone);
        printf("Father's Name: "); getchar(); gets(stu.f_name);
        printf("Mother's Name: "); gets(stu.m_name);
        printf("Father's mobile number: "); scanf("%lld", &stu.f_phone);
        printf("Mother's mobile number: "); scanf("%lld", &stu.m_phone);
        printf("Local guardian's name: "); getchar(); gets(stu.guardian);
        printf("Present address: ");  gets(stu.pre_address);
        printf("Permanent address: ");  gets(stu.per_address);
        printf("Others details and comment: "); gets(stu.others);
        //fprintf(fp, "%lld %s %s %s %lld\n", stu.id, stu.name, stu.guardian, stu.address, stu.phone);
        fwrite(&stu, sizeof(stu), 1, fp);
        fclose(fp);
    }
    cls();
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tThe record is sucessfully added");
    printf("\nDo you want to continue [y/n] : " ); fflush(stdin);
    char c;
    c = getchar();
    if(c=='y')
    {
        cls();
        menu();
        getchoice();
    }
    else if(c=='n')
        exit(0);
    fclose(fp);

}
int get_password(int check){
    char temp_use[100],temp_pass[100], ch, use[30], pass[30];
    int i=0;
    printf("\n\n\n\n\t\t\t\t\t\tThe database is password protected.");
    printf("\n\n\n\n\t\t\t\t\t\tEnter Valid username and password");
    printf("\n\n\n\t\t\tUSERNAME:- "); fflush(stdin); gets(temp_use);
    printf("\n\t\t\tPASSWORD:- "); fflush(stdin);
    while(ch!=13)
    {
        ch=getch();

        if(ch!=13 && ch!=8){
            putch('*');
            temp_pass[i] = ch;
            i++;
        }
    }
    temp_pass[i] = '\0';
    int found=0;
    FILE *fpass;
    fpass = fopen("password.txt", "r");

    while(fscanf(fpass, "%s %s", p.username, p.password)!=EOF){
        if((strcmp(temp_use, p.username)==0) && (strcmp(temp_pass, p.password)==0))
        {
            found=1;
            break;
        }
    }
    fclose(fpass);
    if(check>=5 && found!=1)
    {
        printf("\n\t\t\tYou have tried too many times.\t\t\tYou are not an admin.\t\t\tYou are trying to login illegally.");
        exit(0);
    }
    if(found!=1)
    {
        printf("\n\n\nInvalid information. Try again.");
        check++;
        get_password(check);
    }
    return found;
}

int conf_record(ll s_id){
    //system("color 4");
    ll found=0; char c;
    FILE *fp;
    fp = fopen("record.txt", "r");
    while(fread(&stu,sizeof(stu),1,fp)==1){
        if(s_id==stu.id){
            found = 1;
            break;
        }
    }
    if(found){
        printf("\n\nThe record for the same ID is already in the database. The informations for the ID are given below\n\n\n");
        printf("\n\n\t\tDo you want to see the details-> [y/n]: ");
        fflush(stdin);
        c = getchar();
        if(c=='y')
        {
            printf("\n\n\t\t\tStudent's Details\n");
            printf("\t\t_________________________________\n");
            printf("ID: %lld\n",stu.id);
            printf("Name: %s\n",stu.name);
            printf("Section: %s\n",stu.section);
            printf("Semester: %s\n", stu.semester);
            printf("Department: %s\n",stu.department);
            printf("Student Blood Group: %s\n", stu.blood_group);

            printf("\n\n\n\t\t\tStudent's Background\n");
            printf("\t\t____________________________________\n");

            printf("College Name: %s\n", stu.college_name);
            printf("H.S.C passing year: %d\n", stu.hsc_year);
            printf("H.S.C Result in GPA: %0.2f\n", stu.hsc_result);
            printf("H.S.C Board: %s\n", stu.hsc_board);
            printf("\n\n");
            printf("School Name: %s\n", stu.school_name);
            printf("S.S.C passing year: %d\n", stu.ssc_year);
            printf("S.S.C Result in GPA: %0.2f\n", stu.ssc_result);
            printf("S.S.C Board: %s\n", stu.ssc_board);

            printf("\n\n\n\t\t\tStudent's Contract Information\n");
            printf("\t\t_____________________________________________\n");

            printf("Student's mobile number: %lld\n", stu.phone);
            printf("Father's Name: %s\n", stu.f_name);
            printf("Mother's Name: %s\n",stu.m_name);
            printf("Father's mobile number: %lld\n", stu.f_phone);
            printf("Mother's mobile number: %lld\n", stu.m_phone);
            printf("Local guardian's name: %s\n", stu.guardian);
            printf("Present address: %s\n", stu.pre_address);
            printf("Permanent address: %s\n", stu.per_address);
            printf("Others details and comment: %s\n", stu.others);

            fclose(fp);
        }

        menu();
        getchoice();
        return 0;
    }
    fclose(fp);
    return 1;
}
void search_student(void)
{
    cls();
    //system("color D");
    ll s_id, found=0;
    char c;
    printf("\t\tSearch Record\n");
    printf("Enter ID to search: ");
    scanf("%lld", &s_id);
    FILE *fp;
    fp = fopen("record.txt", "r");//rb
    while(fread(&stu,sizeof(stu),1,fp)==1){
        if(s_id==stu.id){
            found = 1;
            break;
        }
    }
    if(found){
        cls();
        printf("\n\n\t\t\tThe record is Found\n\n\n");
        printf("\n\n\t\t\tStudent's Details\n");
        printf("\t\t_________________________________\n");
        printf("ID: %lld\n",stu.id);
        printf("Name: %s\n",stu.name);
        printf("Section: %s\n",stu.section);
        printf("Semester: %s\n", stu.semester);
        printf("Department: %s\n",stu.department);
        printf("Student Blood Group: %s\n", stu.blood_group);

        printf("\n\n\n\t\t\tStudent's Background\n");
        printf("\t\t____________________________________\n");

        printf("College Name: %s\n", stu.college_name);
        printf("H.S.C passing year: %d\n", stu.hsc_year);
        printf("H.S.C Result in GPA: %0.2f\n", stu.hsc_result);
        printf("H.S.C Board: %s\n", stu.hsc_board);
        printf("\n\n");
        printf("School Name: %s\n", stu.school_name);
        printf("S.S.C passing year: %d\n", stu.ssc_year);
        printf("S.S.C Result in GPA: %0.2f\n", stu.ssc_result);
        printf("S.S.C Board: %s\n", stu.ssc_board);

        printf("\n\n\n\t\t\tStudent's Contract Information\n");
        printf("\t\t_____________________________________________\n");

        printf("Student's mobile number: %lld\n", stu.phone);
        printf("Father's Name: %s\n", stu.f_name);
        printf("Mother's Name: %s\n",stu.m_name);
        printf("Father's mobile number: %lld\n", stu.f_phone);
        printf("Mother's mobile number: %lld\n", stu.m_phone);
        printf("Local guardian's name: %s\n", stu.guardian);
        printf("Present address: %s\n", stu.pre_address);
        printf("Permanent address: %s\n", stu.per_address);
        printf("Others details and comment: %s\n", stu.others);
    }else
        printf("Sorry, no record found in the database\n");
    fclose(fp);
    printf("\nDo you want to continue [y/n] : " ); fflush(stdin);
    c = getchar();
    if(c=='y')
    {
        cls();
        menu();
        getchoice();
    }
    else if(c=='n')
        exit(0);
    return ;
}
void modify_record(void){
    //system("color C");
    cls();
    printf("\t\t\tModify Record\n\n\n");
    ll s_id, found=0;
    printf("Enter ID to Modify: ");
    scanf("%lld", &s_id);
    FILE *fp;
    fp = fopen("record.txt","rb+");//rb+
    while(fread(&stu, sizeof(stu),1,fp) == 1){
        if(s_id==stu.id){
        printf("Name: "); getchar(); gets(stu.name);
        printf("Section: "); gets(stu.section);
        printf("Semester: "); gets(stu.semester);
        printf("Department: "); gets(stu.department);
        printf("Student Blood Group: "); gets(stu.blood_group);

        printf("\n\n\n\t\t\tStudent's Background\n");
        printf("\t\t____________________________________\n");

        printf("College Name: "); gets(stu.college_name);
        printf("H.S.C passing year: "); scanf("%d", &stu.hsc_year);
        printf("H.S.C Result in GPA: "); scanf("%f", &stu.hsc_result);
        printf("H.S.C Board: "); gets(stu.hsc_board);
        printf("\n\n");
        printf("School Name: "); gets(stu.school_name);
        printf("S.S.C passing year: "); scanf("%d", &stu.ssc_year);
        printf("S.S.C Result in GPA: "); scanf("%f", &stu.ssc_result);
        printf("S.S.C Board: "); gets(stu.ssc_board);

        printf("\n\n\n\t\t\tStudent's Contract Information\n");
        printf("\t\t_____________________________________________\n");

        printf("Student's mobile number: "); scanf("%lld", &stu.phone);
        printf("Father's Name: "); gets(stu.f_name);
        printf("Mother's Name: "); gets(stu.m_name);
        printf("Father's mobile number: "); scanf("%lld", &stu.f_phone);
        printf("Mother's mobile number: "); scanf("%lld", &stu.m_phone);
        printf("Local guardian's name: ");  gets(stu.guardian);
        printf("Present address: ");  gets(stu.pre_address);
        printf("Permanent address: ");  gets(stu.per_address);
        printf("Others details and comment: "); gets(stu.others);
        fseek(fp,-sizeof(stu), SEEK_CUR);
        fwrite(&stu,sizeof(stu), 1, fp);
        found = 1;
            break;
        }
    }
    if(!found)
        printf("Sorry, no record found in the database to modify\n\n\n");
    fclose(fp);
    printf("\nDo you want to continue [y/n] : " );
    if(getchar()=='y')
    {
        cls();
        menu();
        getchoice();
    }
    else if(getchar()=='n')
        exit(0);
    return;
}
void delete_record(void){
    cls();
    printf("\t\t\tDelete Record\n\n\n");
    ll s_id, found=0;
    printf("Enter ID to Modify: ");
    scanf("%lld", &s_id);
    FILE *fp, *temp;
    fp = fopen("record.txt","rb");
    temp = fopen("temp.txt", "wb");
    while(fread(&stu, sizeof(stu),1,fp) == 1){
        if(s_id==stu.id){
            continue;
        }
        fwrite(&stu,sizeof(stu),1,temp);
    }
    fclose(fp);
    fclose(temp);
    remove("record.txt");
    rename("temp.txt","record.txt");
    printf("The record is sucessfully deleted");
    printf("\nDo you want to continue [y/n] : " );fflush(stdin);
    char c;
    c=getchar();
    if(c=='y')
    {
        cls();
        menu();
        getchoice();
    }
    else if(c=='n')
        exit(0);
    return;
}
void change_password(void)
{
    char temp_use[100],temp_pass[100], ch, use[30], pass[30];
    int i=0;
    int check=1;
    if(old_password_check(check))
    {
        printf("\n\n\n\n\t\t\t\t\t\tEnter new password");
        printf("\n\t\t\tPASSWORD:- "); fflush(stdin);
        while(ch!=13)
        {
            ch=getch();

            if(ch!=13 && ch!=8){
                putch('*');
                temp_pass[i] = ch;
                i++;
            }
        }
        temp_pass[i] = '\0';
    }

    int found=0;
    FILE *fpass, *ftemp;
    fpass = fopen("password.txt", "rb");
    ftemp = fopen("temp_pass.txt", "wb");
    while(fscanf(fpass, "%s %s", p.username, p.password)!=EOF){
        if((strcmp(old_username, p.username)==0))
        {
            fprintf(ftemp, "%s %s\n", old_username, temp_pass);
            continue;
        }
        fprintf(ftemp, "%s %s\n", p.username, p.password);
    }
    fclose(fpass);
    fclose(ftemp);
    remove("password.txt");
    rename("temp_pass.txt", "password.txt");
    printf("You have changed password");
}
int old_password_check(int check){
    char temp_use[100],temp_pass[100], ch, use[30], pass[30];
    int i=0;
    printf("\n\n\n\n\t\t\t\t\t\tThe database is password protected.");
    printf("\n\n\n\n\t\t\t\t\t\tEnter Valid username and password");
    printf("\n\n\n\t\t\tUSERNAME:- "); fflush(stdin); gets(temp_use);
    printf("\n\t\t\tPASSWORD:- "); fflush(stdin);
    while(ch!=13)
    {
        ch=getch();

        if(ch!=13 && ch!=8){
            putch('*');
            temp_pass[i] = ch;
            i++;
        }
    }
    temp_pass[i] = '\0';
    int found=0;
    FILE *fpass;
    fpass = fopen("password.txt", "r");

    while(fscanf(fpass, "%s %s", p.username, p.password)!=EOF){
        if((strcmp(temp_use, p.username)==0) && (strcmp(temp_use, p.username)==0))
        {
            found=1;
            break;
        }
    }
    fclose(fpass);
    if(check>=5 && found!=1)
    {
        printf("\n\t\t\tYou have tried too many times.\t\t\tYou are not an admin.\t\t\tYou are trying to login illegally.");
        exit(0);
    }
    if(found!=1)
    {
        printf("\n\n\nInvalid information. Try again.");
        check++;
        old_password_check(check);
    }
    int j;
    for(j=0; temp_use[j]!='\0'; j++)
        old_username[j]=temp_use[j];
    old_username[j]='\0';
    return found;
}
