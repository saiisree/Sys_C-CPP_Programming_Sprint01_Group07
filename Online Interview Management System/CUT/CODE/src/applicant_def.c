/***********************************************************************************
 *
 * FILENAME : applicant_def.c
 *
 * DESCRIPTION : This is a definition file for applicant module.
 *
 * ********************************************************************************/

#include"company_header.h"
#include"validation_header.h"
#include"applicant_header.h"
#include"admin_header.h"

/************************************************************************************
 *
 * FUNCTION NAME : applicant_menu
 *
 * DESCRIPTION : displaying the menu for applicant login and register.
 *
 * PARAMETERS : void
 *
 * RETURN TYPE:exit status 0
 *
 * *********************************************************************************/

app* applicant_head = NULL;

int applicant_menu(void)
{
        int option, ret = 0;
        printf("\n.................................Applicant Module..........................\n");
        printf("Press '1' to Register \n");
        printf("Press '2'to Login\n");
        printf("Press '0' to exit\n");
        scanf("%d",&option);
        switch(option)
        {
                case REGISTER:
                        system("clear");
                        applicant_register();
                        break;
                case LOGIN:
                        system("clear");
                        do
                        {
                                ret = applicant_login();
                        }while(ret == 1);
                        break;
                case EXIT:
                          exit(0);
                default:
                        printf("Enter the correct option\n");
        }

}

/*************************************************************************************************
 *
 * FUNCTION NAME : applicant_login
 *
 * DESCRIPTION : In this function ,the applicant logins
 *
 * PARAMETERS : void
 *
 * RETURN TYPE: void
 *
 * ***********************************************************************************************/

int applicant_login(void)
{
        char temp[100];
        char name[10], pwd[10], username[10]={0}, password[10]={0};
        int flag = 0;
        FILE *log;

        printf("\n--------------------------------------LOGIN-----------------------------------------\n\n");
        printf("Please enter your login credentials below: \n");
        printf("\nApplicant Username: ");
        scanf("%s",name);
        strcpy(pwd,getpass("\nApplicant password: "));

        log=fopen("applicant_login.txt","r");
        if(log==NULL)
        {
                printf("Error at opening File!\n");
                exit(0);
        }

        while(fgets(temp,sizeof(temp),log))
        {
                sscanf(temp,"%s , %s\n", username , password);
                if(strncmp(username, name, 10) || strncmp(password, pwd, 10))
                {
                        continue;
                }
                else
                {
                        flag=1;
                        break;
                }
        }
        fclose(log);

        if(flag == 1 )
        {
              printf("\nLogged in successfully\n\n");
              applicant_details_menu(username , password);
        }
	printf("\nLog in failed\n\n");
        return 1;
}

/*******************************************************************************************
 *
 * FUNCTION NAME : applicant_register
 *
 * DESCRIPTION: in this function ,the applicant registers
 *
 * PARAMETERS : void
 *
 * RETURN: once registered, it returns back to applicant_login.
 *
 * ******************************************************************************************/

void applicant_register(void)
{
        char temp[30];
        int ch, ret = 0;
        int value1,value2;
        char username[10]={0},password[10]={0};
        FILE *log;
        log=fopen("applicant_login.txt","a");
        if(log==NULL)
        {
                printf("Error at opening file!\n");
                exit(0);
        }

        printf("---------------------------------------REGISTER------------------------------------\n");
        printf("\nYour username should contain atleast 1 uppercase and 1 lowercase letter and length should not be more than 10 characters\n");
        printf("\nApplicant Username: ");
        scanf("%s",username);
        value1=username_validation(username);
        printf("\nYour password should be atleast 8 characters where it should have 1 uppercase letter, 1 lowercase letter, a digit and a special character \n");
        printf("\nApplicant Password: ");
        scanf("%s",password);
        value2 = password_validation(password);

        if(value1 == 1 && value2 ==  1)
        {
                 printf("\nSuccesfully Registered !! \n");
                 fprintf(log,"%s , %s\n",username , password);
                 printf("\nPress any key to continue (1/0)...\n");
                 scanf("%d",&ch);
                 fclose(log);
        }
        else
        {
                printf("Incorrect username or password\n");
                printf("\nPress any key to continue(1/0)....\n");
                scanf("%d",&ch);
                applicant_register();
        }
        system("clear");
	 do
        {
                ret = applicant_login();
        }while(ret == 1);
        fclose(log);

}

/*************************************************************************************************
 *
 * FUNCTION NAME : applicant_details_menu
 *
 * DESCRIPTION : in this function, it displays the applicant details menu operations such as add,modify and display.
 *
 * PARAMETERS : username and password
 *
 * RETURN : exit status 0
 *
 * ****************************************************************************************************/

int applicant_details_menu(char *username, char *password)
{
        int ch;
        applicant_head=NULL;
        while(1)
        {

                printf("\n-------------------------APPLICANT MENU------------------\n");
                printf("1.Add applicant details\n");
                printf("2.Modify applicant details\n");
                printf("3.Delete applicant details\n");
                printf("4.Display applicant details\n");
                printf("5.Search jobs\n");
                printf("6.Main Menu\n");
                printf("0.Exit\n");
                printf("------------------------------------------------\n");
                printf("Enter the choice : \n");
                scanf("%d",&ch);

                switch(ch)
                {
                        case ADD:
                                system("clear");
                                add_applicant_node(username,password);
                                break;
                                               case MODIFY:
                                modify_applicant_node();
                                break;
                        case DELETE:
                                delete_applicant_node();
                                break;
                        case DISPLAY:
                                 display_applicant(applicant_head);
                                 break;
                        case SEARCHJOBS:
                                 display_openings();
                                 break;
                        case MAINMENU:
                                 main();
                                 break;
			case EXIT:
                                exit(0);
                        defualt:
                                printf("Enter the correct option\n");

                }
       }

}

/**************************************************************************************************
 *
 * FUNCTION NAME : add_applicant_node
 *
 * DESCRIPTION : in this function,the applicant can add the details.
 *
 * PARAMETERS : username and password
 *
 * RETURN : void
 *
 * **************************************************************************************************/

void add_applicant_node(char *username, char *password)
{
        int phonenumber=0,email=0;
        char temp_mail_id[30];
        long int temp_num;
         FILE *appy;
        app* newnode;

        newnode = (app*)malloc(sizeof(app));

        if(newnode==NULL)
        {
                printf("Malloc allocation is failed\n");
                return;
        }

        newnode->next=NULL;

        appy = fopen("applicant_details.txt","a");
        if(appy==NULL)
        {
                printf("Error at opening file!\n");
                exit(0);
        }

        strncpy(newnode->username, username, 10);
        strncpy(newnode->password, password, 10);

        system("clear");
        printf("\n---------------------------------------Applicant Details Information---------------------------\n");


        printf("Applicant name: ");
        scanf("%s",newnode->applicant_name);

        printf("\nAge: ");
        scanf("%d",&newnode->applicant_age);

        printf("\nPhone number: ");
        scanf("%ld",&temp_num);
	if(phone_number_validation(temp_num)==1)
        {
                newnode->applicant_phn_no=temp_num;
                phonenumber++;
        }
        else
        {
                printf("Incorrect phone number\n");
                return;
        }
        printf("\nGender: ");
        scanf("%s",newnode->applicant_gender);

        printf("\nMail Id: ");
        scanf("%s",temp_mail_id);
        if (email_validation(temp_mail_id)==1)
        {
                 strcpy(newnode->applicant_mail_id,temp_mail_id);
                 email++;
        }
        else
        {
                printf("\nInvalid email id");
                return;
        }

        printf("\nQualification: ");
        scanf("%s",newnode->applicant_qualification);
	
        printf("\nSkills: ");
        while(getchar()!='\n');
        fgets(newnode->applicant_skills,30,stdin);
        newnode->applicant_skills[strlen(newnode->applicant_skills)-1]='\0';


        printf("\nAddress: ");
        fgets(newnode->applicant_address,30,stdin);

        fprintf(appy,"%s,%d,%ld,%s,%s,%s,%s,%s\n",newnode->applicant_name,newnode->applicant_age,newnode->applicant_phn_no,newnode->applicant_gender,newnode->applicant_mail_id,newnode->applicant_qualification,newnode->applicant_skills,newnode->applicant_address);
        fclose(appy);

        printf("\nDetails are entered,\n");

        if(applicant_head == NULL)
        {
                applicant_head = newnode;
        }
        else
        {
                newnode->next=applicant_head;
                applicant_head=newnode;
        }

}

/**************************************************************************************************************
 * FUNCTION NAME: modify_applicant_node
 *
 * DESCRIPTION: in this function,the applicant can modify the details.
 *
 * parameters: none
 *
 *return: void

***************************************************************************************************************/

void modify_applicant_node()
{
        int ch;
        long int temp_num;
        int temp_age;
        char temp_add[30],temp_skills[30];
        char temp_mail_id[30];
        char temp_qualification[10];
        app *temp=applicant_head;
        printf("\n enter the applicant mail id to modify the details: ");
        scanf("%s",temp_mail_id);

        while(temp != NULL)
        {
                if(!strcmp(temp->applicant_mail_id,temp_mail_id))
                {
                        printf("\n-----------------------------------Enter the option to be modified----------------------------\n");
                        printf("1.Update age\n");
                        printf("2.Update phone number\n");
                        printf("3.Update qualification\n");
                        printf("4.Update skills\n");
                        printf("5.Update address\n");
                        printf("0.Exit\n");
                        printf("---------------------------------------------------\n");
                        printf("Enter choice : \n");
                        scanf("%d", &ch);
                        switch(ch)
                        {
                                case AGE:
                                        printf("\nEnter the new age to be updated: ");
                                        scanf("%d", &temp_age);
                                        temp->applicant_age=temp_age;
                                        break;
                                case PHNNO:
                                        printf("\nEnter the new phone number to be updated: ");
                                        scanf("%ld", &temp_num);
                                        temp->applicant_phn_no = temp_num;
                                        break;
				 case QUALI:
                                        printf("\nEnter the new qualification to be modified : ");
                                        while(getchar()!='\n');
                                        fgets(temp_qualification,10,stdin);
                                        temp_qualification[strlen(temp_qualification)-1]='\0';
                                        strcpy(temp->applicant_qualification,temp_qualification);
                                        break;
                                case SKILLS:
                                        printf("\nEnter the new skills to be modified : ");
                                        while(getchar()!='\n');
                                        fgets(temp_skills,30,stdin);
                                        temp_skills[strlen(temp_skills)-1]='\0';
                                        strcpy(temp->applicant_skills,temp_skills);
                                        break;
                                case ADDRES:
                                        printf("\nEnter the new address to be updated: \n");
                                        while(getchar()!='\n');
                                        fgets(temp_add,30,stdin);
                                        temp_add[strlen(temp_add)-1]='\0';
                                        strcpy(temp->applicant_address,temp_add);
                                        break;

                                case EXIT:
                                        exit(0);
                                defualt:
                                        printf("\nInvalid choice\n");
                        }
                        break;
                }
                                temp=temp->next;
        }
	if(temp == NULL)
        {
                printf("\nApplicant mail id is not found to modify details\n");
                return;
        }
        update_applicant_NodeFile();

}




/*******************************************************************************************************************
 * FUNCTION NAME: delete_applicant_node
 *
 * DESCRIPTION:in this function,the applicant can delete their details.
 *
 * parameters:none
 *
 * RETURN: void
 *
 * ******************************************************************************************************************/

void delete_applicant_node()
{
        char temp_mail_id[20];
        app *temp = applicant_head, *temp2;
        printf("\nEnter the applicant mail id to delete the details: ");
        scanf("%s",temp_mail_id);
        if(applicant_head==NULL)
        {
                printf("\nThere are no applicants\n");
                return;
        }
        if(!strcmp(applicant_head->applicant_mail_id,temp_mail_id))
        {
                temp=applicant_head->next;
                free(applicant_head);
                applicant_head=temp;
                update_applicant_NodeFile();
                printf("\nApplicant mail id %s found\n",temp_mail_id);
                return;
        }
        for(temp = applicant_head->next, temp2 = applicant_head; temp!= NULL; temp=temp->next, temp2=temp2->next)
        {
                if(!strcmp(temp->applicant_mail_id,temp_mail_id))
                {
                        temp2->next=temp->next;
                        free(temp);
                        update_applicant_NodeFile();
                        printf("\nApplicant mail id %s is found \n",temp_mail_id);
                        return;
                }
        }
        printf("\nApplicant  mail id is %s not found.\n",temp_mail_id);

}

/***************************************************************************************************************
 * FUNCTION NAME : display_applicant
 *
 * DESCRIPTION :it displays the applicant details information
 *
 * PARAMETERS: none
 *
 * RETURN : void
 *
 * *********************************************************************************************************/


void display_applicant()
{
        app *temp = applicant_head;
        while(temp!=NULL)
        {
                printf("\n----------------Details of Applicant---------------\n");
                printf("\nApplicant Name: %s\n",temp->applicant_name);
                printf("\nApplicant age : %d\n",temp->applicant_age);
                printf("\nApplicant gender:%s\n",temp->applicant_gender);
                printf("\nApplicant Phone number: %ld\n",temp->applicant_phn_no);
                printf("\nApplicant mail id:%s\n",temp->applicant_mail_id);
                printf("\nApplicant qualification:%s\n",temp->applicant_qualification);
                printf("\nApplicant skills:%s\n",temp->applicant_skills);
                printf("\nApplicant Address: %s\n",temp->applicant_address);
                temp = temp->next;
                //main();
        }

}


/***********************************************************************************
 * Function Name: update_applicant_NodeFile
 *
 * Description: In this function, it updates the applicant details information into the file.
 *
 * Parameters: None
 *
 * Return: void
 *
 * *********************************************************************************/


void update_applicant_NodeFile()
{
        FILE *appy;
        app *newnode = applicant_head;

        appy = fopen("applicant_details.txt", "w");

        while(newnode != NULL)
        {

                fprintf(appy,"%s,%d,%ld,%s,%s,%s,%s,%s\n",newnode->applicant_name,newnode->applicant_age,newnode->applicant_phn_no,newnode->applicant_gender,newnode->applicant_mail_id,newnode->applicant_qualification,newnode->applicant_skills,newnode->applicant_address);
                newnode=newnode->next;

        }

        fclose(appy);

}

