
/*************************************************************************************
 * FILENAME: company_header.h
 *
 * DESCRIPTION: This is a company module header file.
 *
 * ***********************************************************************************/

                   //Preprocessor directives

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

                        //Defining Macros

//#define ADMIN 1
#define COMPANY 2
//#define APPLICANT 3
#define EXIT 0

#define REGISTER 1
#define LOGIN 2

#define ADD 1
#define MODIFY 2
#define DELETE 3
#define RECENT_OPENINGS 5
#define DISPLAY 4

#define PHNO 1
#define ADDRESS 2
#define DESCRIPTION 3

#define ROLE 1
#define QUALIFICATION 2
#define LOCATION 3
#define PACKAGE 4
#define OP_DATE 5
#define CL_DATE 6


                        //Declaring structures

struct date 			//structure date
{
        int day,mon,year;
};



typedef struct company    	//structure company for company_details
{
        char username[10];
        char password[10];
        char company_id[6];
        char company_name[20];
        char company_address[50];
        char company_description[100];
        long int company_phoneno;
        struct company *next;
} cmp;

typedef struct comp_recent_open 	//structure recent openings of company
{
        char company_name[20];
        int opening_id;
        char job_role[30];
        char qualification[30];
        char location[30];
        long int package;
        struct date op_date;
        struct date cl_date;
        struct comp_recent_open *next;
} r_cmp;

                        //Declaration Functions

//Declaration Functions for Menu, Login and Register for Company


int display_company_menu(void);
int company_login(void);
void company_register(void);
int password_validation(char*);
int username_validation(char*);

//Declaration Functions for Company Details operations such as Menu, Add, Modify and Display

int company_details_menu(char *, char *);
void addnode(char*, char*);
void modifynode();
void deletenode();
void updateNodeFile();
void display();
int phone_number_validation(long int);
int company_id_validation(char*);

//Declaration Functions for Company Details of Recent Openings operations such as Menu, Add, Modify, Delete and Display

int recent_openings_menu(void);
void add_openings();
void display_openings();
void delete_openings();
void updateOpFile();
int opening_id_validation(int);
int date_validation(int,int,int);
void modify_openings();

