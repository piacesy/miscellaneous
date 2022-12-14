#include<stdio.h>
struct abc{
	char a[3];
	char e;
	double d;
};
struct a{
	int e;
	struct abc temp;	
};
struct c{
	char d;
	struct a e;
};
int main(){
	printf("%d\n",sizeof(struct c));
	return 0;
}
