#include<stdio.h>

void swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int a,b,c;
	printf("Enter three integers: ");
	scanf("%d%d%d",&a,&b,&c);
	swap(&a, &b);
	swap(&c, &a);
	printf("Output: %d %d %d\n",a,b,c);
}