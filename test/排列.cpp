#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
char **record;
int ans_num;
void pl(char zfc[],int m,int n);
int cmpfuc(const void*a, const void*b);
int main(){
	char zfc[7]={0};
	gets(zfc);
	int num=1,n,m=0;
	n=strlen(zfc);
	ans_num=0;
	for(int i=1;i<=n;i++){
		num*=i;
	}
	record=(char**)malloc(num*sizeof(char*));
	for(int i=0;i<num;i++){
		record[i]=(char*)malloc(sizeof(char)*7);
	}
	pl(zfc,m,n);
	qsort(record,ans_num,sizeof(char*),cmpfuc);
	for(int i=0;i<ans_num;i++){
		printf("%s\n",record[i]);
	}
	return 0;
}

int cmpfuc(const void *a,const void *b){
    char *str1=*(char**)a;
    char *str2=*(char**)b;
    return strcmp(str1,str2);
}
void pl(char zfc[],int m,int n){
	char b[7],temp1;
	if(m==n){
		strcpy(record[ans_num],zfc);
		ans_num++;
	}
	else{
		for(int i=m;i<n;i++){
			strcpy(b,zfc);
			temp1=zfc[m];
			zfc[m]=zfc[i];
			zfc[i]=temp1;
			pl(zfc,m+1,n);
			strcpy(zfc,b);
		}
	}
}
