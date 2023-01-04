#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node* CreateNode();
struct node* InsertAtStart(struct node* head,int item);
struct node* InsertAtEnd(struct node* head,int item);
struct node*InsertAtMiddle(struct node* head,int item, int index);
struct node* DeleteFromStart(struct node* head);
struct node* DeleteFromEnd(struct node* head);
struct node* DeleteFromMiddle(struct node* head,int item);
void print_DLL();

struct node* CreateNode()
{
	struct node* newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	return newNode;
}

struct node* InsertAtStart(struct node* head,int item)
{
	struct node *newNode;
	newNode = CreateNode();
	newNode->data = item;
	newNode->prev = NULL;
	newNode->next = head;
	head = newNode;
	return head;
}

struct node* InsertAtEnd(struct node* head,int item)
{
	struct node *newNode, *temp;
	newNode = CreateNode();
	newNode->data = item;
	newNode->prev = NULL;
	newNode->next = NULL;
	temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
	return head;
}

struct node* InsertAtMiddle(struct node* head,int item, int index)
{
	struct node *newNode, *temp;
	newNode = CreateNode();
	newNode->data = item;
	newNode->next = NULL;
	newNode->prev = NULL;
	temp = head;
	while(temp->data != index)
	{
		temp = temp->next;
			if(temp == NULL)
		{
			printf("Element not found !\n");
			return;
		}
	}
	newNode->next = temp->next;
	newNode->prev = temp;
	temp->next = newNode;
	newNode->next->prev = newNode;
	return head;
}

struct node* DeleteFromStart(struct node* head)
{
	if(head==NULL)
	{
		printf("Your DLL is empty!\n");
		return;
	}
	else
	{
	struct node *temp = head;
	head = head->next;
	free(temp);
	head->prev = NULL;
	}
	return head;
}

struct node* DeleteFromEnd(struct node* head)
{
	if(head==NULL)
	{
		printf("Your DLL is empty!\n");
		return;
	}
	else
	{
	struct node *temp = head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->prev->next = NULL;
	free(temp);
	}
	return head;
}

struct node* DeleteFromMiddle(struct node* head,int item)
{
	if(head==NULL)
	{
		printf("Your DLL is empty!\n");
		return;
	}
	else
	{
	struct node *temp = head;
	while(temp->data!=item)
	{
		temp = temp->next;
		if(temp == NULL)
		{
			printf("Element not found !\n");
			return;
		}
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	free(temp);
	return head;
	}
}

void print_DLL(struct node* head)
{
	if(head == NULL)
	{
		printf("List is Empty !");
	}
	else
	{
		struct node *temp = head;
		printf("Your DLL : ");
		while(temp != NULL)
		{
			printf("%d ",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main()
{
	int ch, ele, index;
	struct node *Head = NULL;
	printf("1.Insert at Start\n2.Insert at End\n3.Insert at Middle\n4.Delete from Start\n5.Delete from End\n6.Delete from Middle\n");
	printf("7.Exit\n");
	
	while(1)
	{
		printf("Enter your choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element you want to insert : ");
				scanf("%d", &ele);
				Head=InsertAtStart(Head,ele);
				print_DLL(Head);
				break;
			case 2:
				printf("Enter the element you want to insert : ");
				scanf("%d", &ele);
				Head=InsertAtEnd(Head,ele);
				print_DLL(Head);
				break;
			case 3:
				printf("Enter the element you want to insert : ");
				scanf("%d", &ele);
				printf("Enter the element after which you want to insert the new element : ");
				scanf("%d", &index);
				Head=InsertAtMiddle(Head,ele,index);
				print_DLL(Head);
				break;
			case 4:
				Head=DeleteFromStart(Head);
				print_DLL(Head);
				break;
			case 5:
				Head=DeleteFromEnd(Head);
				print_DLL(Head);
				break;
			case 6:
				printf("Enter the element after which you want to delete the element : ");
				scanf("%d", &index);
				Head=DeleteFromMiddle(Head,index);
				print_DLL(Head);
				break;
			case 7:
				exit(1);
			default:
				printf("Invalid Choice!!");
		}
	}
	return 0;
}

