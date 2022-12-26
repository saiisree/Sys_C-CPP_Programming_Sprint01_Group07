/***********************************************************************************************************
 * FILENAME: admin_def.c
 * DESCRIPTION: This is admin module definition file.
 * ***********************************************************************************************************/
#include"admin_header.h"

/***********************************************************************************************************
 * *FUNCTION NAME:Admin_login
 * DESCRIPTION:In this function,the admin logins by providing username and password.
 * PARAMETERS:void
 *************************************************************************************************************/
int admin_login(void)
{
              //int ch;
              int count1 = 0,count2 = 0;
              char username[10],password[10];
              FILE *file;
              char *token;
              char temp[30];

              printf("\nUsername: ");
              scanf("%s",username);

              strcpy(password,getpass("password"));

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
                             printf("Logged in Successfully\n");
                             admin_work();
              }
              else
              {
                             printf("Incorrect username or password\n");
                            // printf("press any key to continue(1/0)....\n");
                            // scanf("%d",&ch);
                             admin_login();
              }
}


/****************************************************************************************************
 * *FUNCTION NAME : admin
 DESCRIPTION:This function is used to perform various operations that has to be performed by the admin
 *****************************************************************************************************/
int admin_work()
{
 int ch;
        printf("\n1.view the company\n2.view the applicant\n3.logout\n");
        scanf("%d",&ch);
        switch(ch)
        {
                case CMP:
                        printf("\ncompany details");
                        //view_company();
                        //company_details_menu();
                        //addnode();
                        //modifynode();
                        //deletenode();
                        //display();
                        break;
                case APP:
                        printf("\napplicant details");
                        //view_applicant();
                        break;
                case LOGOUT:
                        exit(0);
                default:
                        printf("Invalid choice:");
        }//ends the switch
        return EXIT;
}

/*FUNCTION NAME:view_company
 DESCRIPTION:The function is used to perform various maintainance operations on company data by admin.
 */
/*int view_company()
{
        int ch=0;
        printf("\n1.view company details\n2.delete company details\n");
        scanf("%d",&ch);
        switch(ch)
         {
                case 1:
                        company_details();
                        break;
                case 2:
                        delete_company_details();
                        break;
                default:
                        printf("\nInvalid choice");
        }
        return EXIT;
}*/

/*FUNCTION NAME:view_applicant()
 DESCRIPTION:The funtion is used to perform various maintainance operations on applicant data by admin.
  */
/*int view_applicant()
{
        int ch;
        printf("\n1.view applicant details\n2.delete applicant details\n");
        scanf("%d",&ch);
        switch(ch)
        {
                case 1:
                        applicant_details();
                        break;
                case 2:
                        delete_applicant_details();
                        break;

                default:
                        printf("\nInvalid choice");
        }
        return EXIT;
}*/