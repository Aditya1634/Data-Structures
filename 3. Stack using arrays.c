#include<stdio.h>
#define max 10
typedef struct{
	int item[max];
	int top;
}stack;
int isStackfull(stack *stk_ptr)
{
	int retval=0;
	if(stk_ptr->top==max-1)
	{
		retval=1;
	}
	return retval;
}
int isStackempty(stack *stk_ptr)
{
	int retval=0;
	if(stk_ptr->top==-1)
	{
		retval=1;
	}
	return retval;
}
void push_helper(stack *stk_ptr,int key)
{
	int t=isStackfull(stk_ptr);
	if(t==1)
	{
		printf("OVERFLOW\n");
	}
	else
	{
		stk_ptr->top=stk_ptr->top+1;
		stk_ptr->item[stk_ptr->top]=key;
	}
}
int pop_helper(stack *stk_ptr)
{
	int temp;
	int t=isStackempty(stk_ptr);
	if(t==1)
	{
		printf("UNDERFLOW\n");
	}
	else
	{
		temp=stk_ptr->item[stk_ptr->top];
		stk_ptr->top=stk_ptr->top-1;
	}
	return temp;
}
int print_helper(stack *stk_ptr)
{
	int i;
	for(i=0;i<=stk_ptr->top;i++)
	{
		printf("%d",stk_ptr->item[i]);
	}
	printf("\n");
}
int main()
{
	stack s;
	stack *stk_ptr;
	stk_ptr=&s;
	stk_ptr->top=-1;
	push_helper(stk_ptr,10);
	push_helper(stk_ptr,20);
	push_helper(stk_ptr,30);
	push_helper(stk_ptr,40);
	print_helper(stk_ptr);
	pop_helper(stk_ptr);
	print_helper(stk_ptr);
	push_helper(stk_ptr,50);
	print_helper(stk_ptr);
	return 0;
}
