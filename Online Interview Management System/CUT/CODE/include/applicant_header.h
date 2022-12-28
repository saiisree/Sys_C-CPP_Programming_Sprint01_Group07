/*************************************************************************************************
 *
 * FILENAME : applicant_header.h
 *
 * DESCRIPTION : This is a header file for applicant module.
 *
 * ***********************************************************************************************/

/***********************************Preproccesor directives***************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

/***************************************Defining macros*******************************************/

#define ADMIN 1
//#define COMPANY 2
//#define APPLICANT 3
#define EXIT 0

#define REGISTER 1
#define LOGIN 2

#define ADD 1
#define MODIFY 2
#define DELETE 3
#define DISPLAY 4
#define SEARCHJOBS 5
#define MAINMENU 6

#define AGE 1
#define PHNNO 2
#define QUALI 3
#define SKILLS 4
#define ADDRES 5

/************************************Declaring Structure*****************************************/

typedef struct applicant
{
        char username[10];
        char password[10];
        int applicant_age;
        long int applicant_phn_no;
        char applicant_gender[10];
        char applicant_name[20];
        char applicant_mail_id[30];
        char applicant_qualification[10];
        char applicant_skills[30];
        char applicant_address[30];
        struct applicant* next;
}app;

/***************************************Declaring Functions***************************************/

//Functions for applicant menu, login, register.
int applicant_menu(void);
int applicant_login(void);
void applicant_register(void);
int username_validation(char *);
int password_validation(char *);

//Functions for applicant details operations such as menu, add, mofify, display.

int applicant_details_menu(char *, char *);
int phone_number_validation(long int );
int email_validation(char *);
void add_applicant_node(char*,char*);
void modify_applicant_node();
void delete_applicant_node();
void update_applicant_NodeFile();
void display_applicant();

