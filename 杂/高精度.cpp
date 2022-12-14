#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int a[1000];
    int b[1000];
    memset(a,0,1000*sizeof(int));
    memset(b,0,sizeof(int)*1000);
    b[0]=1;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	int temp1=0;
    	for(int j=0;j<999;j++){
    		temp1=b[j]*i+temp1;
    		b[j]=temp1%10;
    		temp1/=10;
		}
		int temp2=0;
			for(int y=0;y<999;y++){
			temp2=(a[y]+b[y])+temp2;
			a[y]=temp2%10;
			temp2/=10;
		}
	}
    int flag=1;
    for(int i=999;i>=0;i--){
        if(a[i]!=0&&flag==1){
            flag=0;
        }
        if(flag==0){
            cout<<a[i];
        }
    }
    return 0;
}
