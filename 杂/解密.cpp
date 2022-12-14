#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int v[8];
	int code1[n][8];
	int code2[n][8];
	for(int i=0;i<8;i++){
		scanf("%d",&v[i]);
	}
	for(int j=0;j<n;j++){
	
		for(int i=0;i<8;i++){
			scanf("%d",&code1[j][i]);
		}
		if(j==0){
			for(int i=0;i<8;i++){
				code2[j][i]=v[i]^code1[j][i];
			}
		}
		else{
			for(int i=0;i<8;i++){
				code2[j][i]=code1[j][i]^code2[j-1][i];
			}
		}
	}
	for(int j=0;j<n;j++){
		int c1=0,c2=0;
		for(int i=0;i<8;i++){
			printf("%04X",code2[j][i]);
			int n1=code1[j][i];
			while(n1>0){
				if(n1%2==1){
					c1++;
				}
				n1/=2;
			}
			int n2=code1[j][i];
			while(n2>0){
				if(n2%16>=10){
					c2++;
				}
				n2/=16;
			}
		}
		printf(" %d %d",c1,c2);
		printf("\n");
	}
	return 0;
}
