/*************************************************************************************************
 * FILENAME : applicant_header.h
 *
 * DESCRIPTION : this is a applicant module header file.
 *
 * ***********************************************************************************************/

                           //preproccesor directives


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>


                          //defining macros


//#define ADMIN 1
//#define COMPANY 2
#define APPLICANT 3
#define EXIT 0


#define REGISTER 1
#define LOGIN 2

#define ADD 1
#define MODIFY 2
#define DELETE 3
#define DISPLAY 4
//#define SEARCHJOBS 5


#define AGE 1
#define PHNNO 2
#define QUALIFICATION 3
#define SKILLS 4
#define ADDRESS 5





                         //declaring struct applicant


typedef struct applicant
{
        char username[10];
        char password[10];
        int applicant_age;
        long int applicant_phn_no;
        char applicant_gender[10];
        char applicant_name[20];
        char applicant_mail_id[20];
        char applicant_qualification[10];
        char applicant_skills[30];
        char applicant_address[30];
        struct applicant* next;
}app;



//functions for menu,login, and register for applicant


int display_applicant_menu(void);    // function to select register or login
int applicant_login(void);          //function for applicant login
void applicant_register(void);       //function for applicant registration
int username_validation(char *);
int password_validation(char *);

//functions for applicant details operations such as menu, add,mofify,display



int applicant_details_menu(char *, char *);
int phone_number_validation(long int );
int email_validation(char *);
void addnode(char*,char*);
void modifynode();
void deletenode();
void updateNodeFile();
void display();



