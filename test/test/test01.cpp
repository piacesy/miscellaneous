#include<stdio.h>
int main(){
	FILE* fp=fopen(".\\test.txt","w");
	fprintf(fp,"this is a test\n");
	return 0;
}
