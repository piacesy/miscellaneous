#include<stdio.h>
int main()
{
	double p1,p2,p3,q1,q2,q3,x;
	int n;
	scanf("%d%.2f%.2f%.2f%.2f%.2f%.2f",&n,&p1,&p2,&p3,&q1,&q2,&q3);
	x=n*(p1*q2+p2*q3+p3*q1);
	printf("%.4f",x);
	return 0;
}
