#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int main(){
    int load;
    cin>>load;
    int pocket[1000];
    memset(pocket,0,sizeof(pocket));
    int pos=0;
    int sum=0;
    for(int i=2;;i++){
        int flag=1;
        for(int j=0;j<pos;j++){
            if(i%pocket[j]==0){
                flag=0;
                break;
            }
        }
        if(flag==1){
        	sum+=i;
            if(sum<=load)
            pocket[pos++]=i;
            else 
            break;
        }
    }
    for(int i=0;i<=pos-1;i++){
        cout<<pocket[i]<<endl;
    }
    cout<<pos;
    return 0;
}
