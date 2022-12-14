#include<stdio.h>
#include<string.h>
#include<ctype.h>
void count(char a[],char w[][10],int n,int b[]){
	for(int i=0;i<n;i++){
		for(int j=0;j<strlen(a)-strlen(w[i])+1;j++){
			if(isalpha(a[j])){
				if(strncmp(w[i],&a[j],strlen(w[i]))==0){
					b[i]++;
				}
				while(isalpha(a[j])){
					j++;
				}
				j--;
			}else{
				while(!isalpha(a[j])){
					j++;
				}
				j--;
			}
		}
	}
}
int main(){
	char a[500];
	gets(a);
	char w[2][10];
	for(int i=0,j=0,k=0;i<strlen(a)&&j<2;i++){
		if(isalpha(a[i])){
			w[j][k]=a[i];
			k++;
		}else{
			while(!isalpha(a[i])){
				i++;
			}
			i--;
			w[j][k]=0;
			k=0;
			j++;
		}
	}
	int b[2]={0,0};
	count(a,w,2,b);
	for(int i=0;i<2;i++){
		printf("%s:%d",w[i],b[i]);
		printf(" ");
	}
	return 0;
}
