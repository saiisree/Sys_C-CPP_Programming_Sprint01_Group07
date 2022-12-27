/***********************************************************************************************************
 * FILENAME: admin_def.c
 *
 * DESCRIPTION: This is admin module definition file.
 *
 ***********************************************************************************************************/

#include"company_header.h"
#include"admin_header.h"
#include"applicant_header.h"

/***********************************************************************************************************
 *
 * FUNCTION NAME:Admin_login
 *
 * DESCRIPTION:In this function,the admin logins by providing username and password.
 *
 * PARAMETERS:void
 *
 *************************************************************************************************************/

int admin_login(void)
{
              int ch;
              int count1 = 0,count2 = 0;
              char username[10],password[10];
              FILE *file;
              char *token;
              char temp[30];

              printf("\nUsername: ");
              scanf("%s",username);

              strcpy(password,getpass("Password: "));

              file = fopen("admin.txt","r");

              if(file == NULL)
                             printf("File not found\n");
              else
              {
                 while(fgets(temp,sizeof(temp),file))
                 {
                        token=strtok(temp,",");

                         while(token!=NULL)
                         {
                               if(strcmp(token,username)==0)
                               {
                                    count1 = 1;
                               }

                                token=strtok(NULL,"\n");

                                if(strcmp(token,password)==0)
                                {
                                    count2 = 1;
                                }
                                      token=strtok(NULL,",");
                         }
                  }
		 }
              if(count1 == 1 && count2 == 1)
              {
                             printf("\nLogged in Successfully\n");
                             admin_task();
              }
              else
              {
                             printf("\nIncorrect username or password\n");
                             printf("\nPress any key to continue(1/0)....\n");
                             scanf("%d",&ch);
                             admin_login();
              }
}


/****************************************************************************************************
 *
 * FUNCTION NAME : admin_task()
 *
 * DESCRIPTION:This function is used to perform various operations that has to be performed by the admin
 *
 * PARAMETERS: void
 *
 *****************************************************************************************************/

int admin_task()
{
 int ch;
        printf("\n1.View the company details");
        printf("\n2.View company recent openings");
        printf("\n3.View the applicant details");
        printf("\n0.Logout\n");
        scanf("%d",&ch);
        switch(ch)
        {
                case CMP:
                        printf("\n--------------Company details--------------\n");
                        company_display();
                        break;
                case CMP_RECOP:
                        printf("\n------------Company Recent Openings-------------\n");
                        display_openings();
                        break;
                case APPLI:
                        printf("\n------------Applicant details------------\n");
                        display_applicant();
                        break;
                case LOGOUT:
                        exit(0);
                default:
                        printf("Invalid choice:");
        }//ends the switch
        return EXIT;
}