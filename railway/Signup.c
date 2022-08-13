#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userData.h"


void pause(); //allows to : Press Enter to Continue
void enterUserName(int); //Enter username function
int compareUserName(char []); //Compares usernames
void enterPhoneNumber(int userNo); //Enter phone number function
int comparePhoneNumber(long phNo); //Compares phone numbers
void signUp(int userNo,char name[]); //signup function



void signUp(int userNo,char name[])
{
    int i;
    i = userNo;
    
    //printf("Your user number is: %d\n",i);
    
    strcpy(user[i].name,name);

    //userName
    enterUserName(i);
    
    printf("Enter password: ");
    fflush(stdin);
    scanf("%[^\n]",user[i].password);

    //phone number
    enterPhoneNumber(i);

    printf("\nSign up Successful!");
    pause();
    
    
    
    
}


void enterUserName(int userNo)
{
    char uName[30];
    printf("\nEnter username: ");
    fflush(stdin);
    scanf("%[^\n]",uName);
    if(compareUserName(uName) == 0)
    {
        printf("\nUser name already exists!\n");
        printf("Try another\n");
        enterUserName(userNo);
    }
    else
    {
        strcpy(user[userNo].userName,uName);
    }
} 


int compareUserName(char uName[])
{ 
    int userNameResult = 0;
    for(int i = 0; i<size;i++){
        if(strcmp(uName,user[i].userName) == 0){
            return userNameResult;
        }
    }    
    userNameResult = 1;
    return userNameResult;
}


void enterPhoneNumber(int userNo)
{
    long phNo;
    printf("Enter phone number: ");
    fflush(stdin);
    scanf("%ld",&phNo);
    if(comparePhoneNumber(phNo) == 0)
    {
        printf("\nPlease enter a unique phone number\n");
        printf("Try again\n");
        enterPhoneNumber(userNo);
    }
    else
    {
        user[userNo].phoneNumber = phNo;
    }

}


int comparePhoneNumber(long phNo)
{
    int phNoResult = 0;
    for(int i = 0; i<size;i++){
        if(phNo == user[i].phoneNumber){
            return phNoResult;
        }
    }
    phNoResult = 1;
    return phNoResult;
}


void pause()
{
    char ch;
    printf("\n\nPress Enter to continue : ");
    fflush(stdin);
    scanf("%c",&ch);
}




