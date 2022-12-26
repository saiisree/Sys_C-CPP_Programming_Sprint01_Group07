/*********************************************************************************** * FILENAME: applicant_definition.c
 *
 * DESCRIPTION : this is a applicant module definition file.
 *
 * ********************************************************************************/
#include"applicant_header.h"

/************************************************************************************
 * FUNCTION NAME : display_applicant_menu
 *
 * DESCRIPTION : displaying the menu for applicant login and register.
 *
 * PARAMETERS : void
 *
 * RETURN:exit status 0
 *
 * *********************************************************************************/

app* head = NULL;

int display_applicant_menu(void)
{
        int option, ret = 0;
        printf("\n.................................applicant Module..........................\n");
        printf("Press '1' to Register \nPress '2'to Login\nPress '0' to exit\n");
        scanf("%d",&option);
        switch(option)
        {
                case REGISTER:
                        system("clear");
                        applicant_register();
                        break;
                case LOGIN:
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
 * DESCRIPTION : in this function ,the applicant logins
 *
 * PARAMETERS : void
 *
 * RETURN: to applicant_login if it fails (1). return to display_applicant_menu if it is true
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
        printf("\napplicant Username: ");
        scanf("%s",name);
        strcpy(pwd,getpass("\napplicant password: "));



        log=fopen("applicant_login.txt","r");
        if(log==NULL)
        {
                printf("error at opening File!\n");
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
        if(flag ==1 )
        {
              printf("\nlogged in successfully\n\n");
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
         printf("\nyour username should contain atleast 1 uppercase and 1 lowercase letter and length should not be more than 10 characters\n");
        printf("\napplicant Username: ");
        scanf("%s",username);
        value1=username_validation(username);
        printf("\nYour password should be atleast 8 characters where it should have 1 uppercase letter, 1 lowercase letter, a digit and a special character \n");
        printf("\napplicant Password: ");
        scanf("%s",password);
        value2 = password_validation(password);

        if(value1 == 1 && value2 ==  1)
        {
                 printf("\nsuccesfully registered !! \n");
                 fprintf(log,"%s , %s\n",username , password);
                 printf("\nPress any key to continue (1/0)...\n");
                 scanf("%d",&ch);
                 fclose(log);
        }
        else
        {
                printf("incorrect username or password\n");
                printf("\npress any key to continue(1/0)....\n");
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
        head=NULL;
        while(1)
        {

                printf("\n-------------------------APPLICANT MENU------------------\n");
                printf("1.add applicant details\n");
                printf("2.modify applicant details\n");
                printf("3.delete applicant details\n");
                printf("4.display applicant details\n");
                printf("5.search jobs\n");
                printf("0.exit\n");
                printf("------------------------------------------------\n");
                printf("enter the choice : \n");
                scanf("%d",&ch);

                switch(ch)
                {
                        case ADD:
                                system("clear");
                                addnode(username,password);
                                break;
                                               case MODIFY:
                                modifynode();
                                break;
                        case DELETE:
                                deletenode();
                                break;
                        case DISPLAY:
                                 display(head);
                                 break;
                /*      case SEARCHJOBS:*/
                        case EXIT:
                                exit(0);
                        defualt:
                                printf("enter the correct option\n");

                }
       }

}
 
/**************************************************************************************************
 *
 * FUNCTION NAME : addnode
 *
 * DESCRIPTION : in this function,the applicant can add the details.
 *
 * PARAMETERS : username and password
 *
 * RETURN : void
 *
 * **************************************************************************************************/
void addnode(char *username, char *password)
{
        int phonenumber=0,email=0;
        char temp_mail_id[20];
        long int temp_num;
         FILE *appy;
        app* newnode;

        newnode = (app*)malloc(sizeof(app));

        if(newnode==NULL)
        {
                printf("malloc allocation is failed\n");
                return;
        }

        newnode->next=NULL;

        appy = fopen("applicant_details.txt","a");
        if(appy==NULL)
        {
                printf("error at opening file!\n");
                exit(0);
        }

        strncpy(newnode->username, username, 10);
        strncpy(newnode->password, password, 10);

        system("clear");
        printf("\n---------------------------------------applicant details information---------------------------\n");


        printf("applicant name: ");
        scanf("%s",newnode->applicant_name);

        printf("\nage: ");
        scanf("%d",&newnode->applicant_age);

        printf("\nphone number: ");
        scanf("%ld",&temp_num);
        if(phone_number_validation(temp_num)==1)
        {
                             newnode->applicant_phn_no=temp_num;
                phonenumber++;
        }
        else
        {
                printf("incorrect phone number\n");
                return;
        }
        printf("\ngender: ");
        scanf("%s",newnode->applicant_gender);

        printf("\nmail id: ");
        scanf("%s",temp_mail_id);
        if (email_validation(temp_mail_id)==1)
        {
                 strcpy(newnode->applicant_mail_id,temp_mail_id);
                 email++;
        }
        else
        {
                printf("\ninvalid email id");
                return;
        }

        printf("\nqualification: ");
        scanf("%s",newnode->applicant_qualification);


        printf("\nskills: ");
        while(getchar()!='\n');
        fgets(newnode->applicant_skills,30,stdin);
        newnode->applicant_skills[strlen(newnode->applicant_skills)-1]='\0';


        printf("\naddress: ");
        fgets(newnode->applicant_address,30,stdin);

            fprintf(appy,"%s,%d,%ld,%s,%s,%s,%s,%s\n",newnode->applicant_name,newnode->applicant_age,newnode->applicant_phn_no,newnode->applicant_gender,newnode->applicant_mail_id,newnode->applicant_qualification,newnode->applicant_skills,newnode->applicant_address);
        fclose(appy);

        printf("\ndetails are entered,\n");

        if(head == NULL)
        {
                head = newnode;
        }
        else
        {
                newnode->next=head;
                head=newnode;
        }

}


/**************************************************************************************************************
 * FUNCTION NAME: modifynode
 *
 * DESCRIPTION: in this function,the applicant can modify the details.
 *
 * parameters: none
 *
 *return: void

***************************************************************************************************************/



void modifynode()
{
	        int ch;
        long int temp_num;
        int temp_age;
        char temp_add[30],temp_skills[30];
        char temp_mail_id[20];
        char temp_qualification[10];
        app *temp=head;
        printf("\n enter the applicant mail id to modify the details: ");
        scanf("%s",temp_mail_id);

        while(temp != NULL)
        {
                if(!strcmp(temp->applicant_mail_id,temp_mail_id))
                {
                        printf("\n-----------------------------------enter the option to be modified----------------------------\n");
                        printf("1.update age\n");
                        printf("2.update phone number\n");
                        printf("3.update qualification\n");
                        printf("4.update skills\n");
                        printf("5.update address\n");
                        printf("0.exit\n");
                        printf("---------------------------------------------------\n");
                        printf("enter choice : \n");
                        scanf("%d", &ch);
                        switch(ch)
                        {
                                case AGE:
                                        printf("\nenter the new age to be updated: ");
                                        scanf("%d", &temp_age);
                                        temp->applicant_age=temp_age;
                                        break;
                                case PHNNO:
                                        printf("\nenter the new phone number to be updated: ");
                                        scanf("%ld", &temp_num);
					                                        temp->applicant_phn_no = temp_num;
                                        break;
                                case QUALIFICATION:
                                        printf("\n enter the new qualification to be modified : ");
                                        while(getchar()!='\n');
                                        fgets(temp_qualification,10,stdin);
                                        temp_qualification[strlen(temp_qualification)-1]='\0';
                                        strcpy(temp->applicant_qualification,temp_qualification);
                                        break;
                                case SKILLS:
                                        printf("\n enter the new skills to be modified : ");
                                        while(getchar()!='\n');
                                        fgets(temp_skills,30,stdin);
                                        temp_skills[strlen(temp_skills)-1]='\0';
                                        strcpy(temp->applicant_skills,temp_skills);
                                        break;
                                case ADDRESS:
                                        printf("\nenter the new address to be updated: \n");
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
                printf("\napplicant mail id is not found to modify details\n");
                return;
        }
        updateNodeFile();

}




/*******************************************************************************************************************
 * FUNCTION NAME: deletenode
 *
 * DESCRIPTION:in this function,the applicant can delete their details.
 *
 * parameters:none
 *
 * RETURN: void
 *
 * ******************************************************************************************************************/


void deletenode()
{
        char temp_mail_id[20];
        app *temp = head, *temp2;
        printf("\nenter the applicant mail id to delete the details: ");
        scanf("%s",temp_mail_id);
        if(head==NULL)
        {
                printf("\nthere are no applicants\n");
                               return;
        }
        if(!strcmp(head->applicant_mail_id,temp_mail_id))
        {
                temp=head->next;
                free(head);
                head=temp;
                updateNodeFile();
                printf("\napplicant mail id %s found\n",temp_mail_id);
                return;
        }
        for(temp = head->next, temp2 = head; temp!= NULL; temp=temp->next, temp2=temp2->next)
        {
                if(!strcmp(temp->applicant_mail_id,temp_mail_id))
                {
                        temp2->next=temp->next;
                        free(temp);
                        updateNodeFile();
                        printf("\n applicant mail id %s is found \n",temp_mail_id);
                        return;
                }
        }
        printf("\napplicant  mail id is %s not found.\n",temp_mail_id);

}





/***************************************************************************************************************
 * FUNCTION NAME : display
 *
 * DESCRIPTION :it displays the applicant details information
 *
 * PARAMETERS: none
 *
 * RETURN : void
 *
 * *********************************************************************************************************/


void display()
{
        app *temp = head;
        while(temp!=NULL)
        {
                printf("\n----------------Details of applicant---------------\n");
                printf("\napplicant Name: %s\n",temp->applicant_name);
                printf("\napplicant age : %d\n",temp->applicant_age);
                printf("\napplicant gender:%s\n",temp->applicant_gender);
                printf("\napplicant Phone number: %ld\n",temp->applicant_phn_no);
                printf("\napplicant mail id:%s\n",temp->applicant_mail_id);
                printf("\napplicant qualification:%s\n",temp->applicant_qualification);
                printf("\napplicant skills:%s\n",temp->applicant_skills);
                printf("\napplicant Address: %s\n",temp->applicant_address);

                temp = temp->next;
        }

}






/***********************************************************************************
 * Function Name: updateNodeFile
 *
 * Description: In this function, it updates the applicant details information into the file.
 *
 * Parameters: None
 *
 * Return: void
 *
 * *********************************************************************************/


void updateNodeFile()
{
        FILE *appy;
        app *newnode = head;

        appy = fopen("applicant_details.txt", "w");

        while(newnode != NULL)
        {

                fprintf(appy,"%s,%d,%ld,%s,%s,%s,%s,%s\n",newnode->applicant_name,newnode->applicant_age,newnode->applicant_phn_no,newnode->applicant_gender,newnode->applicant_mail_id,newnode->applicant_qualification,newnode->applicant_skills,newnode->applicant_address);
                newnode=newnode->next;

        }

        fclose(appy);

}












