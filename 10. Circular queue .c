#include <stdio.h>  
# define max 10  
int queue[max]; 
int front;  
int rear;  
void init()
{
	front=-1;
	rear=-1;
}
int enqueue()  
{  
	int ele;
	if((rear+1)%max==front)    
    {  
        printf("Queue is overflow.\n");  
    }  
    else if(front==-1 && rear==-1)   
    {  
    	printf("Enter the element to enqueue : ");
    	scanf("%d",&ele);
        front=0;  
        rear=0;  
        queue[rear]=ele;  
    }  
    else  
    {  
    	printf("Enter the element to enqueue : ");
    	scanf("%d",&ele);
        rear=(rear+1)%max;       
        queue[rear]=ele;      
    }  
    return rear;
}  
  
int dequeue()  
{  
    if((front==-1) && (rear==-1))  
    {  
        printf("Queue is underflow.\n");  
    }  
 	else if(front==rear)  
	{  
  	    printf("The dequeued element is %d.\n", queue[front]);  
   		front=-1;  
   		rear=-1;  
	}   
	else  
	{  
    	printf("The dequeued element is %d.\n", queue[front]);  
   		front=(front+1)%max;  
	}  
	return front;
}  

void display()  
{  
    int i=front;  
    if(front==-1 && rear==-1)  
    {  
        printf("Queue is empty.\n");  
    }  
    else  
    {  
        printf("Your Queue is :"); 
		printf("<<FRONT>>  ");
        while(i<=rear)  
        {  
            printf("%d  ", queue[i]);  
            i=(i+1)%max;  
        }  
        printf("<<REAR>>");
    }  
}  
int main()  
{  
	int choice=1,x;   
    init();  
    while(choice<4 && choice!=0)   
    {  
    printf("\nEnter 1 for enqueue.");  
    printf("\nEnter 2 for dequeue.");  
    printf("\nEnter 3 for display.");
	printf("\nEnter any other number to quit.");  
    printf("\nEnter your choice : ");  
    scanf("%d", &choice);    
    	switch(choice)  
    	{  
        	case 1:  
        		rear=enqueue();  
        		break;  
        	case 2:  
        		front=dequeue();  
        		break;  
       		case 3:  
        		display();  
        		break;
        	default:
				printf("Invalid Choice !!\n");	
   		}
	}  
    return 0;  
}  
