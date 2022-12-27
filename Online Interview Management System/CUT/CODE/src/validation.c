/*********************************************************************************
 *  FILENAME: validation.c
 *
 *  DESCRIPTION: This is a data validation module
 *
 * *******************************************************************************/



#include"validation_header.h"



/*********************************************************************************
 *  Function Name: password_validation()
 *
 *  Description: In this function, it checks for the password validation i.e, it should contain 1 uppercase, 1 lowercase, 1 digit and 1 special character.
 *
 *  Parameter: password
 *
 *  Return: int value
 *
 * *******************************************************************************/

int password_validation(char *password)
{
        int len,i;
        int small=0,caps=0,num=0,spec_char=0;
        len = strlen(password);
        if(len > 8)
        {
                return FALSE;
        }
        else
        {
                for(i=0;i<len;i++)
                {
                        if((password[i] >= 'a' && password[i] <= 'z'))
                                small++;
                        else if(password[i] >= 'A' && password[i] <= 'Z')
                                caps++;
                        else if(password[i] >= '0' && password[i] <= '9')
                                num++;
                        else if(password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*')
                                spec_char++;
                }
                if(small >= 1 && caps >= 1 && num >= 1 && spec_char >= 1)
                        return TRUE;
                else
                        return FALSE;
        }
}


/*********************************************************************************
 *  Function Name: username_validation()
 *
 *  Description: In this function, it checks for the username validation i.e, it should contain atleast 1 uppercase, 1 lowercase. It should not contain any digit or special character.
 *
 *  Parameter: username
 *
 *  Return: int value
 *
 * *******************************************************************************/

int username_validation(char *username)
{
        int len,i;
        int small=0,caps=0,num=0,spec_char=0;
        len = strlen(username);

        if(len > 10)
        {
                return FALSE;
        }
        else
        {
                for(i=0;i<len;i++)
                {
                        if(username[i] >= 'a' && username[i] <= 'z')
                                small++;
                        else if(username[i] >= 'A' && username[i] <= 'Z')
                                caps++;
                        else if(username[i] >= '0' && username[i] <= '9')
                                num++;
                        else if(username[i] == '!' || username[i] == '@' || username[i] == '#' || username[i] == '$' || username[i] == '%' || username[i] == '^' || username[i] == '&' || username[i] == '*')
                                spec_char++;
                }
                if((len <= 10) || (num >= 1) || (spec_char >= 1))
                {
                        return TRUE;
                }
                else
                {
                        return FALSE;
                }
        }
}

/*********************************************************************************
 *  Function Name: email_validation()
 *
 *  Description: In this function, it checks for the email validation i.e, it should contain 1 @ symbol and 1 .(dot).
 *
 *  Parameter: email
 *
 *  Return: int value
 *
 * *******************************************************************************/

int email_validation(char *email)
{
        int dot = 0, special_char = 0, i, len;
        len = strlen(email);
        for(i=0;i<len;i++)
        {
                if(email[i] == '@')
                        special_char++;

                if(email[i] == '.')
                        dot++;
        }

        if(dot == 1 && special_char == 1)
        {
                if(strlen(email) <= 30)
                {
                        return TRUE;
                }
        }
        else
                return FALSE;
}

/*********************************************************************************
 *  Function Name: admin_validation()
 *
 *  Description: In this function, it checks for the admin validation i.e, it should compare admin's username and password which is stored in file.
 *
 *  Parameter: username and password
 *
 *  Return: int value
 *
 * *******************************************************************************/

int admin_validation(char *username, char *password)
{
        int count1=0,count2=0;
        FILE *file;
        char *token;
        char temp[30];

        file = fopen("admin.txt","r");

        if(file == NULL)
                printf("File is empty\n");
        else
        {
                while(fgets(temp,sizeof(temp),file))
                {
                        token = strtok(temp,",");

                        while(token != NULL)
                        {
                                if(strcmp(token,username) == 0)
                                {
                                        count1 = 1;
                                }

                                token = strtok(NULL,"\n");

                                if(strcmp(token,password) == 0)
                                {
                                        count2 = 2;
                                }

                                token = strtok(NULL,",");
                        }
                }
        }
        if(count1 == 1 && count2 == 1)
                return TRUE;
        else
                return FALSE;
	fclose(file);
}



/*********************************************************************************
 *  Function Name: company_id_validation()
 *
 *  Description: In this function, it checks for the company ID validation i.e, it should contain atleast 1 uppercase and 1 digit. The length of company ID should be 5.
 *
 *  Parameter: company_id
 *
 *  Return: int value
 *
 * *******************************************************************************/

int company_id_validation(char *company_id)
{
        int len,i;
        int small=0,caps=0,num=0,spec_char=0;
        len = strlen(company_id);
        if(len > 5)
        {
                return 0;
        }
        else
        {
                for(i=0;i<len;i++)
                {
                        if((company_id[i] >= 'a' && company_id[i] <= 'z'))
                                small++;
                        else if(company_id[i] >= 'A' && company_id[i] <= 'Z')
                                caps++;
                        else if(company_id[i] >= '0' && company_id[i] <= '9')
                                num++;
                        else if(company_id[i] == '!' || company_id[i] == '@' || company_id[i] == '#' || company_id[i] == '$' || company_id[i] == '%' || company_id[i] == '^' || company_id[i] == '&' || company_id[i] == '*' )
                                spec_char++;
                }
                if(small == 0 && caps >= 1 && num >= 1 && spec_char == 0)
                        return TRUE;
                else
                        return FALSE;
        }
}


/*********************************************************************************
 *  Function Name: opening_id__validation()
 *
 *  Description: In this function, it checks for the opening id validation i.e, it should contain 6 numbers.
 *
 *  Parameter: opening_id
 *
 *  Return: int value
 *
 * *******************************************************************************/

int opening_id_validation(int opening_id)
{
        int count = 0;
        do
        {
                opening_id /= 10;
                count++;
        }while(opening_id != 0);

        if(count == 6)
                return TRUE;
        else
                return FALSE;
}

/*********************************************************************************
 *  Function Name: date_validation()
 *
 *  Description: In this function, it checks for the date validation i.e, it should be in dd/mm/yyyy format.
 *
 *  Parameter: date,month,year
 *
 *  Return: int value
 *
 * *******************************************************************************/

int date_validation(int dd,int mm,int yyyy)
{
        if(yyyy >= 2022 && yyyy <= 2025)
        {
                if(mm >= 1 && mm <= 12)
                {
                        if((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
                                return TRUE;
                        else if((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
                                return TRUE;
                        else if((dd >= 1 && dd <= 28) && (mm == 2))
                                return TRUE;
                        else if(dd == 29 && mm == 2 && (yyyy % 400 == 0 ||(yyyy % 4 == 0 && yyyy % 100 != 0)))
                                return TRUE;
                        else
                                return FALSE;
                }
        }
}


/*********************************************************************************
 *  Function Name: phone_number_validation()
 *
 *  Description: In this function, it checks for the phone number i.e, it should contain 10 numbers and first number be either 6, 7, 8 or 9.
 *
 *  Parameter: phone number
 *
 *  Return: int value
 *
 * *******************************************************************************/

int phone_number_validation(long int phone_number)
{
    int count;
    char result[10];
    int i=0;
    sprintf(result, "%ld", phone_number);
    int len = strlen(result);

    if(len == 10)
    {
        if(result[i] == '9' || result[i] == '8' || result[i] == '7' || result[i] == '6')
            return TRUE;
    }
    else
            return FALSE;
}