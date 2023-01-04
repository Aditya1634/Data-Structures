#include<stdio.h>
#define MAX 5
struct {
	int queue[MAX];
	int rear;
	int front;
}q1;
void initq();
void enqueue();
void dequeue();
void display();

void main()
{
	int choice;
	initq();
	enqueue();
	enqueue();
	display();
	dequeue();
	display();
	dequeue();
	display();	
	dequeue();
	
}
void initq()
{
	q1.front=q1.rear=-1;
}
void enqueue()
{
	int num;
	if(q1.rear==MAX-1)
    	printf("Queue Overflow ");
    else
	{
		if(q1.front==-1)
			q1.front=0;
		printf("Insert the element in the queue : ");
		scanf("%d",&num);
		q1.rear=q1.rear+1;
		q1.queue[q1.rear]=num;
	}	
}
void dequeue()
{
	if(q1.front==-1||q1.front>q1.rear)
	{
		printf("Queue Underflow ");
		return;
	}
	else
	{
		printf("Element deleted from queue is : %d\n",q1.queue[q1.front]);
		q1.front=q1.front+1;
		if(q1.front>q1.rear)
			q1.front=q1.rear=-1;
	}
}
void display()
{
	int i;
	if(q1.front==-1)
		printf("Queue is Empty.");
	else
	{
		printf("Queue is : ");
		printf("<<FRONT>>\t");
		for(i=q1.front;i<=q1.rear;i++)
		{
			printf("%d",q1.queue[i]);
			printf("\t");
		}
		printf("<<REAR>>");
		printf("\n");
	}
}
