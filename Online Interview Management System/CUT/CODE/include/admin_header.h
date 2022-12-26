/*FILENAME:admin_header.h
 * DESCRIPTION:This is admin module header file
 * */
#include<stdio.h>     //Preprocessor directives
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define ADMIN 1  //defining macros
//#define COMPANY 2
//#define APPLICANT 3
#define EXIT 0

#define CMP 1
#define APP 2
#define LOGOUT 0

#define TRUE 1
#define FALSE 0


typedef struct admin_login    //declaring struct admin
{
        char username[20];
        char password[20];
}l;
//function declaration
int admin_login(void);
int admin_work(void);
