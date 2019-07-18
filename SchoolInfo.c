#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
	char name[20];
	char usn[10];
	char clas[2];
	char sec[2];
	int pfees;
	struct student *ptr;
};

typedef struct student node;


node *head=NULL,*start,*cur,*prev,*new1;

void insert(int n)
{
	int check=0;
	
	system("cls");
	printf("*************************************************************");
	printf("\n\t\t\tADD DATA\n");
	printf("*************************************************************\n\n");
	
	new1=(node*)malloc(sizeof(node));

	printf("Enter Name:");
	scanf("%s",new1->name);
	if(n==1)
	{
		printf("\nEnter USN:");
		scanf("%s",new1->usn);
	}
	else
	{
		printf("\nEnter ID:");
		scanf("%s",new1->usn);
	}
	printf("\nEnter class:");
	scanf("%s",new1->clas);
	printf("\nEnter sec:");
	scanf("%s",new1->sec);
	if(n==1)
	{
		printf("\nEnter fees:");
		scanf("%d",&new1->pfees);
	}
	else
	{
		printf("\nEnter Salary:");
		scanf("%d",&new1->pfees);
	}
	new1->ptr=NULL;

	strupr(new1->name);

	if(head==NULL)
	{
		head=new1;
	}
	else if(strcmp(head->name,new1->name)>0)											//ins at beg
	{
		start=head;
		new1->ptr=start;
		head=new1;
	}
	else
	{
		start=head;
		while(start->ptr!=NULL)
		{
			prev=start;
			start=start->ptr;
			if((strcmp(prev->name,new1->name)<0) && (strcmp(start->name,new1->name)>0))
			{
				check=1;
				break;
			}
		}
		if(start->ptr==NULL && check==0)
		{
			start->ptr=new1;
		}
		else
		{
			new1->ptr=prev->ptr;
			prev->ptr=new1;
		}
	}
}

void del()
{
	char key[50];
	
	system("cls");
	printf("*************************************************************");
	printf("\n\t\t\tDELETE DATA\n");
	printf("*************************************************************\n\n");
	
	if(head==NULL)
		printf("Empty\n");
	else
	{
		start=head;
		printf("Enter usn/id to del element : ");
		scanf("%s",&key);
		strupr(key);
		while(strcmp(start->usn,key)!=0 && start->ptr!=NULL)
		{
			prev=start;
			start=start->ptr;
		}
		if(head==start)
			head=start->ptr;
			else
				prev->ptr=start->ptr;
				free(start);
	}
}


void display(int n)
{
	system("cls");
	printf("*************************************************************");
	printf("\n\t\t\tDISPLAY DATA\n");
	printf("*************************************************************\n\n");
	
	if(head==NULL)
		printf("Empty");
	else
	{
		start=head;
		if(n==1)
			printf("\n\nName\tUSN\tClass\tSec\tFEE\n\n");
		else
			printf("\n\nName\tID\tClass\tSec\tSalary\n\n");

		while(start!=NULL)
		{
			printf("%s\t%s\t%s\t%s\t%d\n",start->name,start->usn,start->clas,start->sec,start->pfees);
			start=start->ptr;
		}
	}
}

void modify(int n)
{
	char key[50];
	
	system("cls");
	printf("*************************************************************");
	printf("\n\t\t\tMODIFY DATA\n");
	printf("*************************************************************\n\n");
	
	if(head==NULL)
		printf("Empty\n");
	else
	{
		start=head;
		printf("Enter USN/ID to modify : ");
		scanf("%s",&key);
		strupr(key);
		while(strcmp(start->usn,key)!=0 && start->ptr!=NULL)
		{
			start=start->ptr;
		}
		if(strcmp(start->usn,key)!=0 && start->ptr==NULL)
			printf("Data not found");
		else
		{
			printf("Enter Name:");
			scanf("%s",start->name);
			printf("\nEnter class:");
			scanf("%s",start->clas);
			printf("\nEnter sec:");
			scanf("%s",start->sec);
			if(n==1)
			{
				printf("\nEnter fees:");
				scanf("%d",&new1->pfees);
			}
			else
			{
				printf("\nEnter Salary:");
				scanf("%d",&new1->pfees);
			}
		}
	}
}


int main()
{
	int c,ch;
	char con;
	do
	{
		system("cls");
		printf("*************************************************************");
		printf("\n\tWELCOME TO SCHOOL MANAGEMENT SYSTEM\n");
		printf("*************************************************************\n\n");
		
		printf("1.Access student's data\n2.Access teacher's data\n3.Quit");
		printf("\n\nEnter choice:");
		scanf("%d",&c);

		switch(c)
		{
		case 1:
			system("cls");
			do
			{
				ch=0;
				system("cls");
				printf("*************************************************************");
				printf("\n\tWELCOME TO STUDENT MANAGEMENT SYSTEM\n");
				printf("*************************************************************\n\n");
				printf("1.New student entry\n2.Display data\n3.Delete student data\n4.Modify data\n5.Back\n\n");
				printf("Enter Choice:");
				scanf("%d",&ch);
				switch(ch)
				{
				case 1:
					insert(1);
					break;
				case 2:
					display(1);
					break;
				case 3:
					del();
					break;
				case 4:
					modify(1);
					break;
				}
				getch();
			}while(ch!=5);
			break;

		case 2:
			system("cls");
			do
			{
				ch=0;
				system("cls");
				printf("*************************************************************");
				printf("\n\tWELCOME TO TEACHERS MANAGEMENT SYSTEM\n");
				printf("*************************************************************\n\n");
				printf("1.New teachers entry\n2.Display data\n3.Delete techers data\n4.Modify data\n5.Back\n\n");
				printf("Enter Choice:");
				scanf("%d",&ch);
				switch(ch)
				{
				case 1:
					insert(2);
					break;
				case 2:
					display(2);
					break;
				case 3:
					del();
					break;
				case 4:
					modify(2);
					break;
				}
				getch();
			}while(ch!=5);
			break;
		}
		getch();
	}while(c!=3);

	getch();
}
