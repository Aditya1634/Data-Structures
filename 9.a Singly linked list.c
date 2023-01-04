#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node* next;
};
struct node* InsertAtStart(struct node* head,int key);
struct node* InsertAtMiddle(struct node* head,int key,int l);
struct node* InsertAtEnd(struct node* head,int key);
struct node* DeleteFromStart(struct node* head);
struct node* DeleteFromMid(struct node* head);
struct node* DeleteFromEnd(struct node* head);
struct node* Search_SLL(struct node* head);
void print_SLL(struct node* head);
int main()
{
	int i,j=0,num,l;
	struct node* Head=NULL;
	printf("-------MENU-------\n");
	printf("Enter 1 to insert at start.\nEnter 2 to insert at middle.\nEnter 3 to insert at end.\nEnter 4 to delete from start.\nEnter 5 to delete from middle.\nEnter 6 to delete from end.\nEnter 7 to search an element in SLL.\nEnter 8 to quit.\n");
	while(j!=1)
	{
		printf("\n\nEnter your choice : ");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				printf("Enter the element to be inserted at start : ");
				scanf("%d",&num);
				Head=InsertAtStart(Head,num);
				print_SLL(Head);
				break;
			case 2:
				printf("Enter the element to be inserted at middle : ");
				scanf("%d",&num);
				printf("Enter the element previous after which you have to insert the new element :");
				scanf("%d",&l);
				Head=InsertAtMiddle(Head,num,l);
				print_SLL(Head);
				break;
			case 3:
				printf("Enter the element to be inserted at end : ");
				scanf("%d",&num);
				Head=InsertAtEnd(Head,num);
				print_SLL(Head);
				break;
			case 4:
				Head=DeleteFromStart(Head);
				break;
			case 5:
				Head=DeleteFromMid(Head);
				break;
			case 6:
				Head=DeleteFromEnd(Head);
				break;
			case 7:
				Search_SLL(Head);
				print_SLL(Head);
				break;
			case 8:
				j=1;
				print_SLL(Head);
				break;
			default:
				printf("Invalid Input.");
		}
	}
}
struct node* InsertAtStart(struct node* head,int key)
{
	struct node* nptr;
	nptr=(struct node*)malloc(sizeof(struct node));
	nptr->data=key;
	nptr->next=head;
	head=nptr;
	return head;
}
struct node* InsertAtMiddle(struct node* head,int key,int i)
{
	struct node *nptr,*temp;
	nptr=(struct node*)malloc(sizeof(struct node));
	nptr->data=key;
	nptr->next=NULL;
	temp=head;
	while(temp->data!=i)
	{
		temp=temp->next;
		if(temp == NULL)
		{
			printf("Element not found !\n");
			return head;
		}
	}
		nptr->next=temp->next;
		temp->next=nptr;
		return head;	
}
struct node* InsertAtEnd(struct node* head,int key)
{
	struct node *nptr,*temp;
	nptr=(struct node*)malloc(sizeof(struct node));
	if(head == NULL)
	{
		head=InsertAtStart(head,key);
	}
	else
	{
		nptr->data=key;
		nptr->next=NULL;
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		nptr->next=temp->next;
		temp->next=nptr;
		return head;
	}
}
struct node* DeleteFromStart(struct node* head)
{
	if(head==NULL)
	{
		printf("Your SLL is empty!\n");
	}
	else
	{
		struct node* temp;
		temp=head;
		head=head->next;
		free(temp);
		print_SLL(head);
		return head;
	}
}
struct node* DeleteFromMid(struct node* head)
{
	if(head==NULL)
	{
		printf("Your SLL is empty!\n");
	}
	else
	{
		struct node *temp=head;
		int l;
		printf("Enter the element to be deleted from middle anywhere : ");
		scanf("%d",&l);
		if(temp->data==l)
		{
			head=DeleteFromStart(head);
		}
		else
		{
			while(temp->next->data!=l)
			{	
				temp=temp->next;
				if(temp->next == NULL)
				{
					printf("Element not found !\n");
					return head;
				}	
			}
			struct node *t;
			t=temp->next;
			temp->next=t->next;
			free(t);
			print_SLL(head);
			return head;
		}
	}
}
struct node* DeleteFromEnd(struct node *head)
{
	if(head==NULL)
	{
		printf("Your SLL is empty!\n");
	}
	else
	{
		struct node *nptr,*temp;
		temp=head;
		nptr=(struct node*)malloc(sizeof(struct node));
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		struct node* t;
		t=temp->next;
		free(t);
		temp->next=NULL;
		print_SLL(head);
		return head;
	}
}
struct node* Search_SLL(struct node *head)
{
	struct node *temp;
	temp=head;
	int flag=0,i=1,key;
	if(head==NULL)
	{
		printf("Your SLL is empty!\n");
	}
	else
	{
		printf("Enter the element you want to search : ");
		scanf("%d",&key);
		while(temp!=NULL)
		{
			if(temp->data==key)
			{
				printf("%d is found in your SLL at node %d.\n",key,i);
				flag=1;
				}
			i++;
			temp=temp->next;
		}
		if(flag==0)
		{
			printf("%d not found in your SLL.\n",key);
		}
	}
}
void print_SLL(struct node* head)
{
	struct node* temp=head;
	printf("Your SLL : ");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;		
	}
}
