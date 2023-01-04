#include<stdio.h>
#include<stdlib.h>
#define size 9
struct node
{
    int data;
    struct node *next;
};
struct node *chain[size],*c;
void init()
{
    int i;
    for(i = 0; i < size; i++)
        chain[i] = NULL;
}
void insert(int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    int key = value % size;
    if(chain[key] == NULL)
        chain[key] = newNode;
    else
    {
        struct node *temp = chain[key];
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void search()
{
    int key,index;
    printf("Enter the element to be searched\n");
    scanf("%d",&key);
    index=key%size;
    if(chain[index] == NULL)
        printf("Search element not found\n");
    else
    {
        for(c=chain[index];c!=NULL;c=c->next)
        {
            if(c->data == key)
                {
                    printf("search element found\n");
                    break;
                }
        }
        if(c==NULL)
            printf("Search element not found\n");
   
    }
}
void print()
{
    int i;
    for(i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
        printf("chain[%d]-->",i);
        while(temp)
        {
            printf("%d -->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main()
{
	int choice,i=0,num;
    init();
    printf("-----<< MENU >>-----\n");
    printf("1. Insert\n2. Search\n3. Print\n4. Quit\n");
    while(i==0)
    {
    	printf("Enter your choice : ");
    	scanf("%d",&choice);
    	switch(choice)
    	{
    		case 1:
    			printf("Enter the number to be inserted : ");
    			scanf("%d",&num);
    			insert(num);
    			break;
    		case 2:
				search();
				break;
			case 3:
				print();
				break;
			case 4:
				i=1;
				break;
			default:
				printf("Invalid Choice !\n");				
		}
	}
    return 0;
}
