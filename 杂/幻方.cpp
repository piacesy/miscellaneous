#include<cstring>
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int book[n][n];
    memset(book,0,sizeof(book));
    int x=0;
    int y=n/2;
    for(int i=1;i<=n*n;i++){
        book[x][y]=i;
        if(x==0&&y==n-1){
                x++;

        }
        else if(x==0){
             x=n-1;
             y++;
        }
        else if(y==n-1){
                x--;
                y=0;
        }
        else{
            if(book[x-1][y+1]==0){
                x--;
                y++;
            }
            else{
                x=(x+1)%n;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            printf("%d ",book[i][j]);
        }
        printf("%d\n",book[i][n-1]);
    }
    return 0;
}
