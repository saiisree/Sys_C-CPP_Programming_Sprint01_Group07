/**************************************************************************
 * FILENAME: main_menu_client.c
 *
 * DESCRIPTION: This is a Main Menu of the client file.
 *
 * ***********************************************************************/

#include"company_header.h"

int main()
{
        while(1)
        {
                int choice;
                printf("--------------Main Menu-----------------\n");
                printf("1. Admin\n");
                printf("2. Company\n");
                printf("3. Applicant\n");
                printf("0. Exit\n");
                printf("------------------------------------------\n");
                printf("Please enter your choice:: \n");
                scanf("%d",&choice);
                switch(choice)
                {
                        case ADMIN:
                                        admin_login();          //calling admin login fucntion
                                        break;
                        case COMPANY:
                                        display_company_menu(); //calling company menu function
                                        break;
                        case APPLICANT:
                                        applicant_menu();       //calling applicant menu function
                                        break;
                        case EXIT:
                                        exit(0);
                        default:
                                        printf("Select a correct option\n");
                }
        }
        return 0;
}