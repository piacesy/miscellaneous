#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int min=11;
    int max=-1;
    int num;
    float sum=0;
    for(int i=0;i<n;i++){
        cin>>num;
        if(num>max){
            max=num;
        }
        if(min>num){
            min=num;
        }
        sum+=num;
    }
    sum=sum-min-max;
    float ret=sum/(n-2);
    printf("%.2f",ret);
    return 0;
}
