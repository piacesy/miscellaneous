#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int tree[256]; 
int main(){
    int n;
    cin>>n;
    int begin=1,end=1;
    for(int i=0;i<n;i++){
        begin<<1;
    }
    end=begin*2-1;
    int origin1=begin;
    int origin2=end;
    memset(tree,0,sizeof(tree));
    for(int i=begin;i<=end;i++){
        cin>>tree[i];
    }
    begin/=2;
    end=(end+1)/2-1;
    while(n>0){
        for(int i=begin;i<=end;i++){
            tree[i]=max(tree[2*i],tree[2*i+1]);
        }
        begin/=2;
        end=(end+1)/2-1;
        n--;
    }
    int ans=(tree[1]==tree[2])?tree[3]:tree[2];
    for(int i=origin1;i<=origin2;i++){
        if(tree[i]==ans){
            printf("%d",i-origin1+1);
        }
    }
    return 0;
}
