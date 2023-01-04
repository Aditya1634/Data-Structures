#include <stdio.h>
#include <stdlib.h>
typedef struct Rational
{
    int num;
    int dem;
}rat;

rat add(rat,rat);
rat sub(rat,rat);
rat mul(rat,rat);
rat divd(rat,rat);

int main()
{
    rat n1,n2,n3;
    int ch;
    printf("Enter the First number\t");
    printf("\nNumerator\t");
    scanf("%d",&n1.num);
    printf("Denominator\t");
    scanf("%d",&n1.dem);
    printf("\nEnter the Second number\t");
    printf("\nNumerator\t");
    scanf("%d",&n2.num);
    printf("Denominator\t");
    scanf("\t%d",&n2.dem);
	n3=add(n1,n2);
	
	n3=sub(n1,n2);
	
	n3=mul(n1,n2);

	n3=divd(n1,n2);
	
	return 0;
}

rat add(rat n1,rat n2)
{
    rat n3;
    n3.num=n1.num*n2.dem+n2.num*n1.dem;
    n3.dem=n1.dem*n2.dem;
        if(n3.dem==0)
            {
            printf("Calculation is not possible\n");
            }
        else{
            printf("Addition is %d/%d\n",n3.num,n3.dem);
            }
   return n3;
}
rat sub(rat n1,rat n2)
{
    rat n3;
    n3.num=n1.num*n2.dem-n2.num*n1.dem;
    n3.dem=n1.dem*n2.dem;
     if(n3.dem==0){
        printf("Calculation is not possible\n");
            }
    else{
        printf("Subtration is %d/%d\n",n3.num,n3.dem);
        }

}
rat mul(rat n1,rat n2)
{
    rat n3;
    n3.num=n1.num*n2.num;
    n3.dem=n1.dem*n2.dem;
           if(n3.dem == 0){
                printf("Calculation is not possible\n");
              }
            else{
            printf("Multiplication is %d/%d\n",n3.num,n3.dem);
            }

    return n3;
}
rat divd(rat n1,rat n2)
{
    rat n3;
    n3.num=n1.num*n2.dem;
    n3.dem=n1.dem*n2.num;
     if(n3.dem==0){
                printf("Calculation is not possible\n");
              }
            else{
            printf("Division is %d/%d\n",n3.num,n3.dem);
            }
    return n3;
}
