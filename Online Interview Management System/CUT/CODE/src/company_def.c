/*********************************************************************
 *  FILENAME: company_def.c
 *
 *  DESCRIPTION: This is a Company Module definition file.
 *
 *******************************************************************/

#include"company_header.h"
#include"validation_header.h"

/*******************************************************************
 * Function Name: display_company_menu
 *
 * Description: Displaying the menu for company login and register.
 *
 * Parameters: void
 *
 * Return: Exit Status 0
 *
 ******************************************************************** */

cmp* head = NULL;
r_cmp* rhead = NULL;

int display_company_menu(void)
{
        int option, ret = 0;
        printf("\n------------------Company Module---------------------\n");
        printf("Press '1' to Register \nPress '2' to Login \nPress '0' to Exit\n");
        scanf("%d",&option);
        switch(option)
        {
                case REGISTER:
                        system("clear");
                        company_register();
                        break;
                case LOGIN:
                        system("clear");
                        do
                        {
                                ret = company_login();
                        }while(ret == 1);
                        break;
                case EXIT:
                        exit(0);
                default:
                        printf("Enter the correct option\n");
        }
}

/***********************************************************************************
 * Function Name: company_login
 *
 * Description: In this function, the company logins.
 *
 * Parameters: void
 *
 * Return: To company_login if it Fails (1). Return to display_company_menu if it is True
 *
 ************************************************************************************/

int company_login(void)
{
        char temp[100];
        FILE *log;
        char *token=NULL;
        char name[10], pwd[10] , username[10] = {0}, password[10] = {0};
        int  flag = 0;

        printf("\n--------------------------------------LOGIN-----------------------------------------\n\n");
        printf("Please enter your login credentials below: \n");
        printf("\nCompany Username: ");
        scanf("%s",name);
        strcpy(pwd,getpass("\nCompany Password: "));
        log = fopen("company_login.txt","r");
        if(log==NULL)
        {
                printf("Error at opening File!\n");
                exit(0);
        }
        while(fgets(temp,sizeof(temp),log))
        {
                sscanf(temp,"%s , %s\n", username, password);
                if(strncmp(username, name, 10) || strncmp(password, pwd, 10))
                {
                    continue;
                }
                else
                {
                    flag = 1;
                    break;
                }
        }
        fclose(log);
        if(flag == 1)
        {
            printf("\nLogged in successfully\n\n");
            company_details_menu(username, password);
        }
        printf("\nLog in failed\n\n");
        return 1;
}


/************************************************************************
 * Function Name: company_register
 *
 * Description: In this function, the company registers.
 *
 * Parameters: void
 *
 * Return: Once Registered, it returns back to company_login.
 *
 * **********************************************************************/

void company_register(void)
{
        char *token=NULL;
        char temp[30];
        int ch, ret = 0;
        int value1,value2;
        FILE *log;
        char username[10] = {0}, password[10] = {0};
        log=fopen("company_login.txt","a");
        if(log==NULL)
        {
                printf("Error at opening file!\n");
                exit(0);
        }

        printf("\n---------------------------------------REGISTER------------------------------------\n");
        printf("\nYour Username should contain atleast 1 uppercase and a lowercase letter\n");
        printf("\nCompany Username: ");
        scanf("%s",username);
        value1 = username_validation(username);
        printf("\nYour password should contain 8 characters where it should have 1 uppercase letter, 1 lowercase letter, a digit and a special character \n");
        printf("\nCompany Password: ");
        scanf("%s",password);
        value2 = password_validation(password);

        if(value1 == 1 && value2 == 1)
        {
                printf("\nSuccessfully Registered !! \n");
                fprintf(log,"%s , %s\n",username,password);
                printf("\nPress key to continue (1/0)...\n");
                scanf("%d",&ch);
                fclose(log);
        }
        else
        {
                printf("\nIncorrect Username or Password\n");
                printf("\nPress key to continue (1/0)...\n");
                scanf("%d",&ch);
                company_register();
        }
	system("clear");
        do
        {
                ret = company_login();
        }while(ret == 1);
        fclose(log);

}


/*********************************************************************************
 * Function Name: company_details_menu
 *
 * Description: In this function, it displays the company details menu operations such as add, modify, delete and display.
 *              It also shows the option for recent openings of company.
 *
 * Parameters: username and password
 *
 * Return: Exit Status 0
 *
 * ********************************************************************************/

int company_details_menu(char *username, char *password)
{
        int ch,n,i;
        head=NULL;
        while(1)
        {
                printf("\n------------------Company Menu------------\n");
                printf("1.Add Company Details\n");
                printf("2.Modify Company Details\n");
                printf("3.Delete Company Details\n");
                printf("4.Display Company details\n");
                printf("5.Recent Openings\n");
                printf("6.Main Menu\n");
                printf("0.Exit\n");
                printf("-------------------------------------\n");
                printf("Enter choice : \n");
                scanf("%d", &ch);
                switch (ch)
                {
                        case ADD:
                                system("clear");
                                addnode(username, password);
                                break;
                        case MODIFY:
                                modifynode();
                                break;
                        case DELETE:
                                deletenode();
                                break;
                        case RECENT_OPENINGS:
                                recent_openings_menu();
                                break;
                        case DISPLAY:
                                company_display(head);
                                break;
                        case MAINMENU:
                                main();
                                break;
                        case EXIT:
                                exit(0);
			default:
                                printf("Enter the correct option\n");
                }
        }
}


/**************************************************************************
 * Function Name: Addnode
 *
 * Description: In this fuction, the company can add the details.
 *
 * Parameters: username and password
 *
 * Return: void
 *
 * ************************************************************************/

void addnode(char *username, char *password)
{

        int id = 0, phonenumber = 0;
        FILE *cmpy;
        char temp[100];
        long int temp_num;
        cmp* newnode;

        newnode = (cmp*)malloc(sizeof(cmp));

        if(newnode == NULL)
        {
                printf("Malloc Allocation is failed\n");
                return;
        }

        newnode->next = NULL;

        cmpy = fopen("company_details.txt","a");
        if(cmpy == NULL)
        {
                printf("Error at opening file!\n");
                exit(0);
        }

        strncpy(newnode->username, username, 10);
        strncpy(newnode->password, password, 8);

        system("clear");
        printf("\n---------------------Company Details Information -------------------------\n");
        printf("\nCompany Name: ");
        scanf("%s",newnode->company_name);

        printf("\nCompany ID: ");
        scanf("%s",temp);
        if(company_id_validation(temp)==1)
        {
                strcpy(newnode->company_id,temp);
                id++;
	}
        else
        {
                printf("\nIncorrect company id. \nCompany id should contain total 5 characters. Atleast 1 uppercase and 1 number\n");
                return;
        }

        printf("\nCompany Phone Number: ");
        scanf("%ld",&temp_num);
        if(phone_number_validation(temp_num)==1)
        {
                newnode->company_phoneno = temp_num;
                phonenumber++;
        }
        else
        {
                printf("\nIncorrect phone number\n");
                return;
        }

        printf("\nCompany Address: ");
        while(getchar()!='\n');
        fgets(newnode->company_address,50,stdin);
        newnode->company_address[strlen(newnode->company_address)-1]='\0';

        printf("\nCompany Description: ");
        fgets(newnode->company_description,100,stdin);

        fprintf(cmpy,"%s,%s,%ld,%s,%s\n",newnode->company_name,newnode->company_id,newnode->company_phoneno,newnode->company_address,newnode->company_description);
        fclose(cmpy);

        printf("\nDetails are entered.\n");
	 if(head == NULL)
        {
                head = newnode;
        }
        else
        {
                newnode->next = head;
                head = newnode;
        }
}



/**************************************************************************
 * Function Name: modifynode
 *
 * Description: In this fuction, the company can modify the details.
 *
 * Parameters: None
 *
 * Return: void
 *
 * ************************************************************************/

void modifynode()
{
        int ch;
        long int temp_num;
        char temp_add[50],temp_des[100];
        char id[5];
        cmp *temp = head;
        printf("\nEnter the Company ID to modify the details: ");
        scanf("%s", id);

        while(temp != NULL)
        {
                if(!strcmp(temp->company_id, id))
                {
                        printf("\n------------------Enter the option to be modified ------------\n");
                        printf("1.Update Phone number\n");
                        printf("2.Update Company Address\n");
                        printf("3.Update Company Description\n");
                        printf("0.Exit\n");
                        printf("-------------------------------------\n");
                        printf("Enter choice : \n");
                        scanf("%d", &ch);
                        switch(ch)
                        {
                                case PHNO:
                                        printf("\nEnter the new Phone number to be updated: ");
                                        scanf("%ld", &temp_num);
                                        temp->company_phoneno = temp_num;
                                        break;
                                case ADDRESS:
                                        printf("\nEnter the new company address to be updated: \n");
                                        while(getchar()!='\n');
                                        fgets(temp_add,50,stdin);
                                        temp_add[strlen(temp_add)-1]='\0';
                                        strcpy(temp->company_address,temp_add);
                                        break;
				case DESCRIPTION:
                                        printf("\nEnter the new company description to be updated: \n");
                                        while(getchar()!='\n');
                                        fgets(temp_des,100,stdin);
                                        temp_des[strlen(temp_des)-1]='\0';
                                        strcpy(temp->company_description,temp_des);
                                        break;
                                case EXIT:
                                        exit(0);
                                default:
                                        printf("\nInvalid Choice\n");
                        }
                        break;
                }
                temp = temp->next;
        }
        if(temp == NULL)
        {
                printf("\nCompany ID not found to modify\n");
                return;
        }
        updateNodeFile();
}


/**************************************************************************
 * Function Name: deletenode
 *
 * Description: In this fuction, the company can delete the details.
 *
 * Parameters: None
 *
 * Return: void
 *
 * ************************************************************************/

void deletenode()
{
        char id[5];
        cmp *temp = head, *temp2;
        printf("\nEnter the Company ID to delete the details: ");
        scanf("%s", id);

        if(!strcmp(head->company_id, id))
        {
                temp = head->next;
                free(head);
                head = temp;
                updateNodeFile();
                return;
        }
        for(temp = head->next, temp2 = head; temp != NULL; temp = temp->next, temp2 = temp2->next)
        {
                if(!strcmp(temp->company_id, id))
                {
                        temp2->next = temp->next;
                        free(temp);
                        updateNodeFile();
                        return;
                }
        }
        printf("\nCompany id %s not found.\n",id);

}

/********************************************************************************
 * Function Name: company_display
 *
 * Description: It displays the company details information
 *
 * Parameters: None
 *
 * Returns: void
 *
 * ******************************************************************************/


void company_display()
{
        cmp *temp = head;
        while(temp!=NULL)
        {
                printf("\n----------------Details of Company---------------\n");
                printf("\nCompany Name: %s\n",temp->company_name);
                printf("\nCompany ID: %s\n",temp->company_id);
                printf("\nCompany Phone number: %ld\n",temp->company_phoneno);
                printf("\nCompany Address: %s\n",temp->company_address);
                printf("\nCompany Description: %s\n", temp->company_description);
                temp = temp->next;
                //main();
                //company_details_menu();
        }

}

/***********************************************************************************
 * Function Name: updateNodeFile
 *
 * Description: In this function, it updates the company details information into the file.
 *
 * Parameters: None
 *
 * Return: void
 *
 * *********************************************************************************/


void updateNodeFile()
{
        FILE *cmpy;
        cmp *newnode = head;

        cmpy = fopen("company_details.txt", "w");

        while(newnode != NULL)
        {
                fprintf(cmpy,"%s,%s,%ld,%s,%s\n",newnode->company_name,newnode->company_id,newnode->company_phoneno,newnode->company_address,newnode->company_description);
                newnode = newnode->next;
        }

        fclose(cmpy);

}

/**************************************************************************
 * Function Name: recent_openings_menu
 *
 * Description: In this function, it displays the menu for recent openings of the company
 *
 * Parameters: void
 *
 * Return: Exit Status 0
 *
 * **************************************************************************/

int recent_openings_menu(void)
{
        int ch,n,i;
        rhead=NULL;
        while(1)
        {
                printf("\n------------------Company Recent Openings Menu------------\n");
                printf("1.Add Recent Opening\n");
                printf("2.Modify Recent Opening\n");
                printf("3.Delete Recent Openings\n");
                printf("4.Display Recent Openings \n");
                printf("5.Main Menu\n");
                printf("0.Exit\n");
                printf("-------------------------------------\n");
                printf("Enter choice : \n");
                scanf("%d", &ch);
                switch (ch)
                {
			 case ADD:
                                system("clear");
                                add_openings();
                                break;
                        case MODIFY:
                                modify_openings();
                                break;
                        case DELETE:
                                delete_openings();
                                break;
                        case DISPLAY:
                                display_openings();
                                break;
                        case MENU:
                                main();
                                break;
                        case EXIT:
                                exit(0);
                        default:
                                printf("Enter the correct option\n");
                }
        }
}


/********************************************************************************
 * Function Name: add_openings
 *
 * Description: In this function, it adds the details of the company recent openings
 *
 * Paramters: None
 *
 * Return: void
 *
 * **************************************************************************

void add_openings()
{
        FILE *op;
        int id=0;
        char temp[100];
        int temp_id;
        struct date op_date;
        struct date cl_date;
        r_cmp* newnode;
        newnode = (r_cmp*)malloc(sizeof (r_cmp));

        if(newnode == NULL)
        {
                printf("Malloc allocation is failed\n");
                return;
        }

        newnode->next = NULL;

        op = fopen("company_recent_openings.txt","a");
        if(op == NULL)
        {
                printf("Error at opening file!\n");
                exit(0);
        }

        system("clear");
        printf("\n---------------------Company Recent Openings Information -------------------------\n");
        printf("\nCompany Name: ");
        scanf("%s",newnode->company_name);

        printf("\nOpening Id: ");
        scanf("%d",&temp_id);
        if(opening_id_validation(temp_id)==1)
        {
                newnode->opening_id = temp_id;
        }
        else
        {
                printf("Incorrect opening id \nOpening id should contain 6 numbers\n");
		return;
        }

        printf("\nJob Role: ");
        while(getchar()!='\n');
        fgets(newnode->job_role,30,stdin);
        newnode->job_role[strlen(newnode->job_role)-1]='\0';

        printf("\nRequired Qualification: ");
        scanf("%s",newnode->qualification);

        printf("\nCurrent Location: ");
        scanf("%s",newnode->location);

        printf("\nPackage: ");
        scanf("%ld",&newnode->package);

        printf("\nOpening Date (dd/mm/yyyy): ");
        scanf("%d/%d/%d",&op_date.day,&op_date.mon,&op_date.year);
        if(date_validation(op_date.day,op_date.mon,op_date.year)==1)
        {
                newnode->op_date.day = op_date.day;
                newnode->op_date.mon = op_date.mon;
                newnode->op_date.year = op_date.year;
        }
        else
        {
                printf("Incorrect Opening Date\n");
                return;
        }
	printf("\nClosing Date (dd/mm/yyyy: ");
        scanf("%d/%d/%d",&cl_date.day,&cl_date.mon,&cl_date.year);
        if(date_validation(cl_date.day,cl_date.mon,cl_date.year)==1)
        {
                newnode->cl_date.day = cl_date.day;
                newnode->cl_date.mon = cl_date.mon;
                newnode->cl_date.year = cl_date.year;
        }
        else
        {
                printf("Incorrect Closing Date\n");
                return;
        }

        fprintf(op,"%s,%d,%s,%s,%s,%ld,%d/%d/%d,%d/%d/%d\n",newnode->company_name,newnode->opening_id,newnode->job_role,newnode->qualification,newnode->location,newnode->package,newnode->op_date.day,newnode->op_date.mon,newnode->op_date.year,newnode->cl_date.day,newnode->cl_date.mon,newnode->cl_date.year);
        fclose(op);

        printf("\nDetails are entered.\n");
        if(rhead == NULL)
        {
                rhead = newnode;
        }
        else
        {
                newnode->next = rhead;
                rhead = newnode;
        }
}

/************************************************************************
 * Function Name: display_openings
 *
 * Description: In this function, it displays the company recent openings information
 *
 * Parameters: None
 *
 * Return: void
 *
 * *********************************************************************/


void display_openings()
{
        r_cmp *temp = rhead;
        while(temp!=NULL)
        {
                printf("\n----------------Details of Company Recent Openings---------------\n");
                printf("\nCompany Name: %s\n",temp->company_name);
                printf("\nOpening id: %d\n",temp->opening_id);
                printf("\nJob Role: %s\n",temp->job_role);
                printf("\nRequired Qualification: %s\n",temp->qualification);
                printf("\nCurrent Location: %s\n",temp->location);
                printf("\nPackage: %ld\n",temp->package);
                printf("\nOpening Date: %d/%d/%d\n",temp->op_date.day,temp->op_date.mon,temp->op_date.year);
                printf("\nClosing Date: %d/%d/%d\n",temp->cl_date.day,temp->cl_date.mon,temp->cl_date.year);
                temp = temp->next;
                //main();
        }
}

/******************************************************************************************
 * Function Name: updateOpFile
 *
 * Description: In this function, it updates the company recent openings information into the file
 *
 * Parameters: None
 *
 * Return: void
 *
 * *****************************************************************************************/



void updateOpFile()
{
        FILE *op;
        r_cmp *newnode = rhead;

        op = fopen("company_recent_openings.txt", "w");

        while(newnode != NULL)
        {
            fprintf(op,"%s,%d,%s,%s,%s,%ld,%d/%d/%d,%d/%d/%d\n",newnode->company_name,newnode->opening_id,newnode->job_role,newnode->qualification,newnode->location,newnode->package,newnode->op_date.day,newnode->op_date.mon,newnode->op_date.year,newnode->cl_date.day,newnode->cl_date.mon,newnode->cl_date.year);
            newnode = newnode->next;
        }

        fclose(op);
}


/***************************************************************************
 * Function Name: delete_openings
 *
 * Description: In this function, it deletes the information in the company recent openings information.
 *
 * Parameters: None
 *
 * Return: void
 *
 * *************************************************************************/


void delete_openings()
{
        int temp_id;
        r_cmp *temp = rhead, *temp2;
        printf("\nEnter company opening id to be deleted: ");
        scanf("%d",&temp_id);

        if(rhead == NULL)
        {
                printf("\nThere are no openings\n");
                return;
        }

        if(rhead->opening_id == temp_id)
        {
                temp = rhead->next;
                free(rhead);
                rhead = temp;
                updateOpFile();
                printf("\nOpening id %d found\n",temp_id); //found in rhead
                return;
        }
	for(temp = rhead->next, temp2 = rhead; temp!=NULL; temp = temp->next, temp2 = temp2->next)
        {
                if(temp->opening_id = temp_id)
                {
                        temp2->next = temp->next;
                        free(temp);
                        updateOpFile();
                        printf("\nOpening id %d found\n",temp_id); //found in else
                        return;
                }
        }
        printf("\nOpening id %d not found.\n",temp_id);
}


/******************************************************************************************
 * Function Name: modify_openings
 *
 * Description: In this function, it modifies or updates the company recent openings information
 *
 * Parameters: None
 *
 * Return: void
 *
 * *****************************************************************************************/

void modify_openings()
{
        int ch;
        int temp_id,temp_dd,temp_mm,temp_yyyy;
        long int temp_pkg;
        char temp_role[30],temp_quali[30],temp_loc[30];
        r_cmp *temp = rhead;

        printf("Enter the Opening id to be modified: \n");
        scanf("%d",&temp_id);
        while(temp != NULL)
        {
                if(temp->opening_id == temp_id)
                {
                        printf("\n--------------Enter the option to be modified----------------- \n");
                        printf("1.Update Job Role\n");
                        printf("2.Update Qualification\n");
                        printf("3.Update Location\n");
                        printf("4.Update Package\n");
                        printf("5.Update Opening Date\n");
                        printf("6.Update Closing Date\n");
                        printf("0.Exit");
                        printf("-----------------------------------------------------------------\n");
                        printf("Enter Choice: \n");
                        scanf("%d",&ch);
                        switch(ch)
                        {
				case ROLE:
                                        printf("\nEnter the new Job Role to be updated: ");
                                        while(getchar()!='\n');
                                        fgets(temp_role,30,stdin);
                                        temp_role[strlen(temp_role)-1]='\0';
                                        strcpy(temp->job_role,temp_role);
                                        break;
                                case QUALIFICATION:
                                        printf("\nEnter the new Qualification to be updated: ");
                                        while(getchar()!='\n');
                                        fgets(temp_quali,30,stdin);
                                        temp_quali[strlen(temp_quali)-1]='\0';
                                        strcpy(temp->qualification,temp_quali);
                                        break;
                                case LOCATION:
                                        printf("\nEnter the new location to be updated: ");
                                        while(getchar()!='\n');
                                        fgets(temp_loc,30,stdin);
                                        temp_loc[strlen(temp_loc)-1]='\0';
                                        strcpy(temp->location,temp_loc);
                                        break;
                                case PACKAGE:
                                        printf("\nEnter the new package to be updated: ");
                                        scanf("%ld",&temp_pkg);
                                        temp->package = temp_pkg;
                                        break;
                                case OP_DATE:
                                        printf("\nEnter the opening date to be updated: ");
                                        scanf("%d/%d/%d",&temp_dd,&temp_mm,&temp_yyyy);
                                        temp->op_date.day = temp_dd;
                                        temp->op_date.mon = temp_mm;
                                        temp->op_date.year = temp_yyyy;
                                        break;
				case CL_DATE:
                                        printf("\nEnter the opening date to be updated: ");
                                        scanf("%d/%d/%d",&temp_dd,&temp_mm,&temp_yyyy);
                                        temp->cl_date.day = temp_dd;
                                        temp->cl_date.mon = temp_mm;
                                        temp->cl_date.year = temp_yyyy;
                                        break;
                                case EXIT:
                                        exit(0);
                                default:
                                        printf("\nEnter the correct option\n");
                        }
                        break;
                }
                temp = temp->next;
        }
        if(temp == NULL)
        {
                printf("\nOpening ID not found to modify\n");
                return;
        }
        updateOpFile();
}
