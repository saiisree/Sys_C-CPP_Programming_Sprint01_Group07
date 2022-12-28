/*********************************************************************************
 *  FILENAME: validation_header.h
 *
 *  DESCRIPTION: This is a header file for data validation.
 *
 *********************************************************************************/



/************************** PRE PROCESSOR DIRECTIVES *****************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*************************** DEFINING MACROS *************************************/

#define TRUE 1
#define FALSE 0

/***************************** FUNCTION DECLARATION *******************************/

int password_validation(char *);
int username_validation(char *);
int email_validation(char *);
int admin_validation(char *, char *);
int company_id_validation(char *);
int opening_id_validation(int);
int date_validation(int,int,int);
int phone_number_validation(long int);
