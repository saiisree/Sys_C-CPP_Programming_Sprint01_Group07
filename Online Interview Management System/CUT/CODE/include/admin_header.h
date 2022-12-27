/************************************************************************************************
 *
 * FILENAME: admin_header.h
 *
 * DESCRIPTION: This is header file for admin module.
 *
 ************************************************************************************************/

/***************************Pre Processor Directives*********************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

/**************************************Defining Macros*******************************************/

#define ADMIN 1
#define EXIT 0

#define CMP 1
#define APPLI 3
#define CMP_RECOP 2
#define LOGOUT 0

#define TRUE 1
#define FALSE 0

/*****************************Declaring structure for admin module*******************************/

typedef struct admin_login
{
        char username[20];
        char password[20];
}l;

/*************************************Function declaration****************************************/
int admin_login(void);
int admin_task(void);