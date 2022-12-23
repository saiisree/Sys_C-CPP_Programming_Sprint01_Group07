//This is a Company Module definitions file.

#include"company_header.h"

int display_company_menu(void)          //Displaying Company Login or Register
{
        int option, ret = 0;
        printf("Company Module\n");
        printf("Press '1' to Register \nPress '2'to Login\n");
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
                default:
                        printf("Enter the correct option\n");
        }
}

int company_login(void)         //Company Login
{
        char username[20],password[20];
        char temp[100];
        FILE *log;
        struct company_login l;
        char *token=NULL;

        printf("\n--------------------------------------LOGIN-----------------------------------------\n\n");
        printf("Please enter your login credentials below: \n");
        printf("\nCompany Username: ");
        scanf("%s",username);
	printf("\nCompany Password: ");
        scanf("%s",password);
        printf("\nThe entered Login Credentials are: \n");
        printf("\nCompany Username: %s\n",username);
        printf("Company Password: %s\n", password);
        log = fopen("company_login.txt","r");
        if(log==NULL)
        {
                printf("Error at opening File!\n");
                exit(0);
        }
        while(fgets(temp,sizeof(temp),log))
        {
                token=strtok(temp,",");
                while(token!=NULL)
                {
                        printf("\nTokenization values are: \n");
                        printf("Company Username Token: %s\n",token);
                        printf("Company username: %s\n",username);
                        if(strncmp(token, username, 20))
                        {
                            printf("Username / Password doesn't match\n");
                            return 1;
                        }
                        token=strtok(NULL,"\n");
                        printf("Company Password Token: %s\n",token);
                        printf("Company Password: %s\n",password);
                        if(strncmp(token, password, 20))
                        {
                            printf("Username / Password doesn't match\n");
                            return 1;
                        }
                        token=strtok(NULL,",");
                }
        }
        printf("\nLogged in successfully\n\n");
	fclose(log);
        return 0;
}

void company_register(void)             //Company Registeration
{
        char username[20],password[20];
        char *token=NULL;
        char temp[30];
        int ch, ret = 0;
        FILE *log;
        struct company_login l;
        log=fopen("company_login.txt","w");
        if(log==NULL)
        {
                printf("Error at opening file!\n");
                exit(0);
        }

        printf("---------------------------------------REGISTER------------------------------------\n");
        printf("\nCompany Username: ");
        scanf("%s",l.username);
        printf("\nYour password should be atleast 8 characters where it should have 1 uppercase letter, 1 lowercase letter, a digit and a special character \n");
        printf("\nCompany Password: ");
        scanf("%s",l.password);
        fprintf(log,"%s,%s\n",l.username,l.password);
        printf("\nSuccessfully Registered !! \n");
        printf("\nPlease provide your login credentials.\n");
        printf("\nPress key to continue (1/0)...\n");
        scanf("%d",&ch);
        fclose(log);

        log=fopen("company_login.txt","r");
        if(log==NULL)
        {
                printf("Error at opening file!\n");
                exit(0);
        }

        while(fgets(temp,30,log)!=NULL)
        {
                printf("\nRecord:");
                token=strtok(temp,",");
                while(token!=NULL)
		{
                        printf("%s\t",token);
                        token=strtok(NULL,",");
                }
                printf("\n");
        }
        fclose(log);

        system("clear");
        do
        {
                ret = company_login();
        }while(ret == 1);

}