#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int randInt(int min,int max);
int main(){
	printf("-----------------------------------------------\n");
	for(int i=0;i<100;i++){
		printf("a%d\n",randInt(1,100));
	}
	return 0;
}
int randInt(int min,int max){
	srand((unsigned)time(NULL));
	int i=max-min+1;
	return (rand()%i)+1;
}
