#include<stdio.h>
typedef struct{
	int real;
	int img;
}complex_tag;

complex_tag add(complex_tag a,complex_tag b)
{
	complex_tag c;
	c.real=a.real+b.real;
	c.img=a.img+b.img;
	return c;
}

complex_tag sub(complex_tag a,complex_tag b)
{
	complex_tag c;
	c.real=a.real-b.real;
	c.img=a.img-b.img;
	return c;
}

int main()
{
	complex_tag x,y,ad,sb;
	printf("Enter the 1st complex number :");
	scanf("%d %d",&x.real,&x.img);
	printf("Enter the 2nd complex number :");
	scanf("%d %d",&y.real,&y.img);
	ad=add(x,y);
	sb=sub(x,y);
	printf("\n ADDITON : %d + %di ",ad.real,ad.img);
	printf("\n SUBTRACTION : %d + (%di) ",sb.real,sb.img);
return 0;
}
