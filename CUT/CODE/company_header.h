//This is a company module header file.
#include<stdio.h>       //Preprocessor directives
#include<string.h>
#include<stdlib.h>

//#define ADMIN 1               //Defining Macros
#define COMPANY 2
//#define APPLICANT 3
#define EXIT 0

#define REGISTER 1
#define LOGIN 2

struct company_login            //Declaring struct company
{
        char username[20];
        char password[20];
};

int display_company_menu(void);
int company_login(void);                //Defintion Functions
void company_register(void);