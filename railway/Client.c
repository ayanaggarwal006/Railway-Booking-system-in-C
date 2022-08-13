#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Signup.c"
#include "TrainDiagram.c"
#include "booking.c"



void login();
void forgotPassword();
void mainMenu();
void menu();
void ticketMenu();
int nameIndex(char []);
void changePassword(); //changes password of user
int userNo(char []); // gives user number to user during sign in

//Global Variables and arrays
char nameList[10][30] = {"empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"}; //stores names of users
int count = 0;
int check = 1;


//int counter = 0; //waiting list counter variable if tickets are full
//int num = 0; // registration number of ticket booked
int main()
{   
    trainDiagram();
    mainMenu();
    
    return 0;
}

int userNo(char name[])
{
    
    int i;
    int pos;

    for(i = count; i<size;i++){

        if(strcmp(name,"empty") !=0){
            strcpy(nameList[i],name);
            pos = i;
            break;
        }
    }
    
    return pos;
        
}

void mainMenu()
{
    int choice;
    char name[20];
    int userNumber;
    
    system("clear");
    printf("\n\n\n");
    printf("============================================================= RAILWAY TICKET RESERVATION SYSTEM ============================================================");
    printf("\n\n");
    printf("========================================================================= MAIN MENU ========================================================================");
    printf("\n\n");
    printf("==> (1) SIGN UP \n");
    printf("==> (2) LOGIN   \n");
    printf("==> (3) EXIT    \n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        system("clear");
        printf("\n\n\n");
        printf("============================================================= RAILWAY TICKET RESERVATION SYSTEM ============================================================");
        printf("\n\n");
        printf("========================================================================= SIGN UP ========================================================================== ");
        printf("\n\nEnter your name: ");
        fflush(stdin);
        scanf("%[^\n]",name);
        userNumber = userNo(name);
        signUp(userNumber,name);
        count++;
        break;
    
    case 2:
        login();
        break;
    
    case 3:
        exit(0);
    
    default:
        printf("\nWrong Input Try again");
        mainMenu();
        break;
    }
    
    mainMenu();

}

void login()
{
    
    char userName[20];
    char password[20];
    
    system("clear");
    printf("\n\n\n");
    printf("============================================================= RAILWAY TICKET RESERVATION SYSTEM ============================================================");
    printf("\n\n");
    printf("========================================================================= LOGIN ============================================================================");
    
    printf("\n\nPlease enter your username and password :");
    printf("\n\nEnter username: ");
    fflush(stdin);
    scanf("%[^\n]",userName);

    printf("Enter password: ");
    fflush(stdin);
    scanf("%[^\n]",password);

    for(int i = 0 ; i < size; i++){

        if(strcmp(userName,user[i].userName) == 0 && strcmp(password,user[i].password) == 0)
        {

            printf("\nLogin Successful!\n");
            pause();
            menu();
            

        }
        else if(strcmp(userName,user[i].userName) != 0 && strcmp(password,user[i].password) != 0)
        {
            if(check > 1)
            {
                int choice;
                printf("\n");
                printf("\nLogin Failed!\n\n");
                printf("==> (1)GO TO FORGOT PASSWORD\n");
                printf("==> (2)LOGIN AGAIN\n");
                printf("\nEnter your choice: ");
                scanf("%d",&choice);
                switch (choice)
                {
                    case 1:
                        forgotPassword();
                        break;
            
                    case 2:
                        check++;
                        login();
                        break;
            
                    default:
                        break;
                }

            }
            else
            {
                printf("\n\nLogin Failed Try again\n");
                check++;
                pause();
                login();    
        
            }

        }

        
    }
    

}
void forgotPassword()
{
    int index;
    long int phoneNo;
    char nameOfUser[30];
    system("clear");
    printf("\n\n\n");
    printf("============================================================= RAILWAY TICKET RESERVATION SYSTEM ============================================================");
    printf("\n\n");
    printf("===================================================================== FORGOT PASSWORD ======================================================================");
    
    printf("\n\n");
    printf("\nEnter your name: ");
    fflush(stdin);
    scanf("%[^\n]",nameOfUser);
    index = nameIndex(nameOfUser);
    
    printf("\nEnter your phone number: ");
    scanf("%ld",&phoneNo);
    

    if(phoneNo == user[index].phoneNumber){
            printf("\nYour new password is: ");
            printf("admin");
            check = 0;
            strcpy(user[index].password,"admin");
            pause();
            mainMenu();
        }
    printf("\n\nWrong input Try again");
    pause();
    forgotPassword();

}
void menu()
{
    int choice;
    system("clear");
    printf("\n\n\n");
    printf("============================================================= RAILWAY TICKET RESERVATION SYSTEM ============================================================");
    printf("\n\n");
    printf("========================================================================== MENU ============================================================================");
    printf("\n\n");
    printf("==> (1) CHANGE PASSWORD \n");
    printf("==> (2) TICKET BOOKING  \n");
    printf("==> (3) GO TO MAIN MENU \n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        changePassword();
        break;
    
    case 2:
        ticketMenu();
        break;
    
    case 3:
        mainMenu();
        break;

    default:
        printf("\nWrong input try again!");
        pause();
        menu();
        break;
    }
    
}

void changePassword()
{  
    int index;
    long int phoneNo;
    char nameOfUser[30];
    char newPassword[30];
    system("clear");
    printf("\n\n\n");
    printf("============================================================= RAILWAY TICKET RESERVATION SYSTEM ============================================================");
    printf("\n\n");
    printf("===================================================================== CHANGE PASSWORD ======================================================================");
    
    printf("\n\n");

    printf("\nEnter your name: ");
    fflush(stdin);
    scanf("%[^\n]",nameOfUser);
    index = nameIndex(nameOfUser);
    
    printf("\nEnter your phone number: ");
    scanf("%ld",&phoneNo);
    

    if(phoneNo == user[index].phoneNumber){
        printf("Enter new password: ");
        fflush(stdin);
        scanf("%[^\n]",newPassword);

        strcpy(user[index].password,newPassword); 
        printf("\nPassword Changed Successfully!\n");
        pause();
        menu();
    }
    printf("Wrong input Try again");
    pause();
    changePassword();

}

int nameIndex(char nameOfUser[])
{
    int i;
    for( i= 0; i <size ;i++){
        if(strcmp(nameList[i],nameOfUser) == 0){
            return i;
        }
    }
    printf("\nWrong Input");
    printf("\nTry again");
    pause();
    changePassword();
    return 0; //does not reach
}

void ticketMenu()
{
	int choice, status=0,canc=0, reg=0;
	start=NULL;
	rear=NULL;
	front=NULL;
	
	
	int ch =0;
	while(ch!=4)
	{
	system("clear");
    printf("\n\n\n");
    printf("============================================================= RAILWAY TICKET RESERVATION SYSTEM ============================================================");
    printf("\n\n");
    printf("======================================================================= TICKET MENU ========================================================================");
    
    printf("\n\n");
    printf("==> (1)BOOK TICKET \n");
    printf("==> (2)CANCEL TICKET\n");
    printf("==> (3)DISPLAY TICKET\n");
	printf("==> (4)GO TO MENU\n");
    printf("==> (5)EXIT\n");
    
	printf("\nEnter your choice: ");
    scanf("%d",&choice);
	switch(choice)
	{	
		case 1 :  
    system("clear");
    printf("\n\n\n");
    printf("============================================================= RAILWAY TICKET RESERVATION SYSTEM ============================================================");
    printf("\n\n");
    printf("======================================================================== BOOK TICKET =======================================================================");
    printf("\n\n");
        status=reserve(start);
	            if(status==0)
	                {
                        
                    printf("\nBooking Full.You are added to waiting list.\nWaiting list number %d", counter);
                    pause();
                    }
                else
	                {
                    printf("\nBooking Successful.Enjoy your journey!\nYour Reg No is %d\n\n", num);
                    pause();
                    }
	            break;
	        
	    case 2: 
    system("clear");
    printf("\n\n\n");
    printf("============================================================= RAILWAY TICKET RESERVATION SYSTEM ============================================================");
    printf("\n\n");
    printf("====================================================================== CANCEL TICKET =======================================================================");
    printf("\n\n");
                display();  
                printf("\nEnter the Registration number to be cancelled : ");
	            scanf(" %d", &reg);
	            if(reg>num)
	            {
                printf("\nInvalid!");
	            pause();
                }
                else
	            {
	                canc=cancel(reg);
	                if(canc==-1)
	              	    {
                        printf("\nRegistration number invalid!\n");
                        pause();
                        }
                    else
	              	    {
                        printf("\nRegistration cancelled successfully\n");
                        pause();
                        }
	            }
	            break;
	              
	    case 3: 
        system("clear");
    	printf("\n\n\n");
    	printf("============================================================= RAILWAY TICKET RESERVATION SYSTEM ============================================================");
    	printf("\n\n");
    	printf("========================================================================== TICKET ==========================================================================");
    	printf("\n\n");
    
        display();
	    break;
	
		case 4: menu();
		break;

		case 5: exit(0);   
	    break;

	    default: printf("\nWrong choice!\n");       
	    break;         
	                 
		          
	
	}
	
}

}
