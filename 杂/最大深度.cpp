#include<iostream>
#include<cstring>
#define MAX 1000
using namespace std;
int lt[MAX];
int rt[MAX];
int _max = 0;
int deepth = 0; 
void built(int i){
   cin>>lt[i];
   cin>>rt[i];
}
void dfs(int num){
    deepth++;
    if(lt[num]==0&&rt[num]==0){
       if(deepth>_max){
       	 _max=deepth;
	   }
        deepth--;
        return ;
    }
    if(lt[num]!=0){
        dfs(lt[num]);
    }
    
    if(rt[num]!=0){
        dfs(rt[num]);
    }
    
    deepth--;
    return;
}
int main(){
    memset(lt,0,sizeof(lt));
    memset(rt,0,sizeof(rt));
    int n,i=1;
    cin>>n;
    while(n--){
        built(i);
        i++;
    }
    dfs(1);
    cout<<_max;
    return 0;
}
