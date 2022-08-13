#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define sizeData 10


struct fileData
{
	int RegistrationNo;
	char personName[30];
	char personGender[20];
	int personAge;	
	char train[30];
	char time[30];
	char travel[100];
	char seatC[30];
	int seat;
	int fare;

};

struct fileData fData[100];


typedef struct NODE
{
	int reg_no;
	char gender[20];
	int age;
	char name[50];
	char trainName[30];
	char trainTime[30];
	char trainTravel[100];
	char seatClass[30];
	int seatNo;
	int seatFare;
	struct NODE *next;
} node;

node* deq();
void create();
int reserve(node*);
int cancel(int);
void enq(node*);
void display();
void dataFile(int);
void availableTrains();
void chooseTrain(node*);
void seatClass(node*);
void seatBook(node*);
void seatMatrix1();
void seatMatrix2();
void seatMatrix3();
void seatMatrix4();



node *start;
node *front;
node *rear;
int counter=0;
int num=0;
int fIndex = 0;

void create( )
{

	node *new;
	new=(node *)malloc(sizeof(node));
	new->reg_no=1;
	printf("\nEnter Passenger's Name: ");
	fflush(stdin);
	scanf("%[^\n]", new->name);
	printf("Enter Passenger's Age : ");
	scanf("%d", &new->age);
	printf("Enter Passenger's Gender (Male/Female) : ");
	fflush(stdin);
	scanf("%[^\n]", new->gender);
	availableTrains();
	chooseTrain(new);
	start=new;
	new->next=NULL;
	num++;
	
}

int reserve(node *start)
{
	
	if(start==NULL)
	{
   		 create();
		 return 1;
	}
	else 
	{
	
	node *temp, *new_node;
	temp=start;
	while(temp->next!=NULL)
	{ 
	  temp=temp->next;
	}
	
	new_node=(node *)malloc(sizeof(node));
	
	printf("\nEnter Passenger's Name: ");
	fflush(stdin);
	scanf("%[^\n]",new_node->name);
	printf("Enter Passenger's Age : ");
	scanf("%d", &new_node->age);
	printf("Enter Passenger's Gender (Male/Female): ");
	fflush(stdin);
	scanf("%[^\n]",new_node->gender);
	availableTrains();
	chooseTrain(new_node);
	new_node->next=NULL;
	if(num<=sizeData)
	{
		num++;
		new_node->reg_no=num;
		temp->next=new_node;
		
		return 1;
	}
	else
	{
		enq(new_node);
		return 0;
	}
}
}


int cancel(int reg)
{
	
	node *ptr, *preptr, *new;
	ptr=start;
	preptr=NULL;
	if(start==NULL)
	return -1;
	if(ptr->next==NULL && ptr->reg_no==reg)
		{
		start=NULL;
		num--;
		free(ptr);
		return 1;
		
		}
		
	else{	
	while(ptr->reg_no!=reg && ptr->next!=NULL)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		if(ptr==NULL && ptr->reg_no!=reg)
			return -1;
		else
			preptr->next=ptr->next;
		free(ptr);
		new=deq();
		while(preptr->next!=NULL)
			preptr=preptr->next;
		preptr->next=new;
		num--;
		return 1;
	
	}
}

void enq(node *new_node)
{
	if(rear==NULL)
	{
		rear=new_node;
		rear->next=NULL;
		front=rear;
	}
	else
	{
		node *temp;
		temp=new_node;
		rear->next=temp;
		temp->next=NULL;
		rear=temp;
	}
	counter++;
}

node* deq()
{
	node *front1;
	front1=front;
	if(front==NULL)
		return NULL;
	else
	{
	    counter-- ;
		if(front->next!=NULL)
		{
			front=front->next;
			front1->next=NULL;
			return front1;
		}
		else
		{
			front=NULL;
			rear=NULL;
			
			return front1;
		}
	}	
			
	
}


void display()
{
	
	char pName[30];
	node *temp;
	temp = start;
	if(temp == NULL)
	{
		printf("\nNo Tickets to display.");
	}
	while(temp!=NULL)
	{

		printf("\nRegistration Number: %d\n", temp->reg_no);
		fIndex = temp->reg_no -1 ;
		
		printf("Name : %s\n", temp->name);
		printf("Age : %d\n", temp->age);
		printf("Gender: %s\n", temp->gender);
		printf("Train Name: %s\n", temp->trainName);
		printf("Journey: %s\n", temp->trainTravel);
		printf("Train Time: %s\n", temp->trainTime);
		printf("Seat Class: %s\n", temp->seatClass);
		printf("Seat No: %d\n", temp->seatNo);
		printf("Fare: %d\n", temp->seatFare);

		fData[fIndex].RegistrationNo = temp->reg_no;
		strcpy(fData[fIndex].personName,temp->name);
		fData[fIndex].personAge = temp->age;
		strcpy(fData[fIndex].personGender,temp->gender);
		strcpy(fData[fIndex].train,temp->trainName);
		strcpy(fData[fIndex].travel,temp->trainTravel);
		strcpy(fData[fIndex].time,temp->trainTime);
		strcpy(fData[fIndex].seatC,temp->seatClass);
		fData[fIndex].seat = temp->seatNo;
		fData[fIndex].fare = temp->seatFare;
		dataFile(fIndex);

		temp=temp->next;
		
		
    }
	
	fIndex++;
	pause();
    
}

void dataFile(int i)
{

	FILE *fptr;
	fptr = fopen("RailwayData.txt","a+");
	if(fptr == NULL)
	{
		printf("\nFile can't be opened");
		exit(1);
	}
	fprintf(fptr,"%s","\nRegistration No: ");
	fprintf(fptr,"%d",fData[i].RegistrationNo);
	fprintf(fptr,"%s","\t\tPassenger Name: ");
	fprintf(fptr,"%s",fData[i].personName);
	fprintf(fptr,"%s","\t\tPassenger Age: ");
	fprintf(fptr,"%d",fData[i].personAge);
	fprintf(fptr,"%s","\t\tPassenger Gender: ");
	fprintf(fptr,"%s",fData[i].personGender);
	fprintf(fptr,"%s","\t\tTrain Name: ");
	fprintf(fptr,"%s",fData[i].train);
	fprintf(fptr,"%s","\t\tJourney: ");
	fprintf(fptr,"%s",fData[i].travel);
	fprintf(fptr,"%s","\t\tTime: ");
	fprintf(fptr,"%s",fData[i].time);
	fprintf(fptr,"%s","\t\tSeat Class: ");
	fprintf(fptr,"%s",fData[i].seatC);
	fprintf(fptr,"%s","\t\tSeat No: ");
	fprintf(fptr,"%d",fData[i].seat);
	fprintf(fptr,"%s","\t\tFare: ");
	fprintf(fptr,"%d",fData[i].fare);
	fclose(fptr);
}

void availableTrains()
{
	printf("\nThe Following Trains are available.\n\n");
	printf("\t====================================================================================================\n");
	printf("\t||  Train No  ||     Train Name        ||   Time   ||          Station                            ||\n");
	printf("\t====================================================================================================\n");
	printf("\t||     1      ||  Rajdhani Express     || at 10:27 || Delhi Station to Mumbai Station             ||\n");
	printf("\t||     2      ||  Shatabdi Express     || at 17:15 || Bhuvaneshwar Station to Bangalore Station   ||\n");
	printf("\t||     3      ||  Humsafar Express     || at 23:35 || Kolkata Station to Hyderabad Station        ||\n");
	printf("\t||     4      ||  Garib-Rath Express   || at 05:46 || Srinagar Station to Chandigarh Station      ||\n");
	printf("\t||     5      ||  Duronto Express      || at 01:59 || Ahmedabad Station to Pune Station           ||\n");
	printf("\t====================================================================================================\n");
}


void chooseTrain(node *new)
{
	int choice;
	printf("\n\nEnter Train No: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			strcpy(new->trainName,"Rajdhani Express");
			strcpy(new->trainTime,"10:47");
			strcpy(new->trainTravel,"Delhi to Mumbai");
			seatClass(new);
			break;
		
		case 2:
			strcpy(new->trainName,"Shatabdi Express");
			strcpy(new->trainTime,"17:45");
			strcpy(new->trainTravel,"Bhuvaneshwar to Bangalore");
			seatClass(new);
			break;
		
		case 3:
			strcpy(new->trainName,"Humsafar Express");
			strcpy(new->trainTime,"23:35");
			strcpy(new->trainTravel,"Kolkata to Hyderabad");
			seatClass(new);
			break;

		
		case 4:
			strcpy(new->trainName,"Garib-Rath Express");
			strcpy(new->trainTime,"05:46");
			strcpy(new->trainTravel,"Srinagar to Chandigarh");
			seatClass(new);
			break;
		
		case 5:
			strcpy(new->trainName,"Duronto Express");
			strcpy(new->trainTime,"01:59");
			strcpy(new->trainTravel,"Ahmedabad to Pune");
			seatClass(new);
			break;
		
		default:
			printf("\nWrong input try again!");
			chooseTrain(new);
			break;		
	}
}

void seatClass(node *new)
{
	int choice;
	printf("\nWhich class would you like to travel in?");
	printf("\n\t 1.First Class   (Rs 4500)");
	printf("\n\t 2.Second AC     (Rs 3000)");
	printf("\n\t 3.Third AC      (Rs 1800)");
	printf("\n\t 4.Sleeper       (Rs 900)");
	printf("\n\t 5.Chair         (Rs 500)");
	printf("\n\nEnter your choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		strcpy(new->seatClass,"First Class");
		new->seatFare = 4500;
		seatMatrix3();
		seatBook(new);
		break;

		case 2:
		strcpy(new->seatClass,"Second AC");
		new->seatFare = 3000;
		seatMatrix2();
		seatBook(new);
		break;

		case 3:
		strcpy(new->seatClass,"Third AC");
		new->seatFare = 1800;
		seatMatrix1();
		seatBook(new);
		break;

		case 4:
		strcpy(new->seatClass,"Sleeper");
		new->seatFare = 900;
		seatMatrix1();
		seatBook(new);
		break;


		case 5:
		strcpy(new->seatClass,"Chair");
		new->seatFare = 500;
		seatMatrix4();
		seatBook(new);
		break;

		default:
			printf("\nWrong input try again!");
			seatClass(new);
			break;
	}
}


//for sleeper and  third AC 
void seatMatrix1()
{
	printf("\n\n");
	printf("\t================== SEAT MATRIX =================\n");
	printf("\t||  (U)   ||   (M)   ||  (L)  || (SU) || (SL) ||\n");
	printf("\t|| 01 02  ||  03 04  || 05 06 ||  07  ||  08  ||\n");
	printf("\t|| 09 10  ||  11 12  || 13 14 ||  15  ||  16  ||\n");
	printf("\t|| 17 18  ||  19 20  || 21 22 ||  23  ||  24  ||\n");
	printf("\t|| 25 26  ||  27 28  || 29 30 ||  31  ||  32  ||\n");
	printf("\t================================================\n");

	printf("\n NOTE");
	printf("\nU  - Upper");
	printf("\nM  - Middle");
	printf("\nL  - Lower");
	printf("\nSU - Side Upper");
	printf("\nSL - Side Lower");


}

//for second AC
void seatMatrix2()
{
	printf("\n\n");
	printf("\t============= SEAT MATRIX ===========\n");
	printf("\t||  (U)   ||  (L)  || (SU) || (SL) ||\n");
	printf("\t|| 01 02  || 03 04 ||  05  ||  06  ||\n");
	printf("\t|| 07 08  || 09 10 ||  11  ||  12  ||\n");
	printf("\t|| 13 14  || 15 16 ||  17  ||  18  ||\n");
	printf("\t|| 19 20  || 21 22 ||  23  ||  24  ||\n");
	printf("\t=====================================\n");

	printf("\n NOTE");
	printf("\nU  - Upper");
	printf("\nL  - Lower");
	printf("\nSU - Side Upper");
	printf("\nSL - Side Lower");
}

//for first AC
void seatMatrix3()
{
	printf("\n\n");
	printf("\t===== SEAT MATRIX ===\n");
	printf("\t||  (U)  ||  (L)  ||\n");
	printf("\t|| 01 02 || 03 04 ||\n");
	printf("\t|| 05 06 || 07 08 ||\n");
	printf("\t|| 09 10 || 11 12 ||\n");
	printf("\t|| 13 14 || 15 16 ||\n");
	printf("\t=====================\n");

	printf("\n NOTE");
	printf("\nU  - Upper");
	printf("\nL  - Lower");
}

// for chair
void seatMatrix4()
{
	printf("\n\n");
	printf("\t============= SEAT MATRIX ================\n");
	printf("\t||  (Window)  ||  (Middle)  || (Aisle) ||\n");
	printf("\t||   01 02    ||   03 04    ||  05 06  ||\n");
	printf("\t||   07 08    ||   09 10    ||  11 12  ||\n");
	printf("\t||   13 14    ||   15 16    ||  17 18  ||\n");
	printf("\t||   19 20    ||   21 22    ||  23 24  ||\n");
	printf("\t==========================================\n");
}

void seatBook(node *new)
{
	printf("\n\nEnter seat number: ");
	scanf("%d",&new->seatNo);
}