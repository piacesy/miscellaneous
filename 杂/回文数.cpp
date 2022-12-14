#include<iostream>
#include<set>
using namespace std;
set<int>ans;
int fac(int i){
	int ret=1;
	for(int j=0;j<i;j++){
		ret*=10;
	}
	return ret;
}
int dfs(int n,int begin,int sum){
	if(begin>n-begin+1){
		ans.insert(sum);
		return 0;
	}
	if(begin<n-begin+1){
		for(int i=0;i<=9;i++){
			if(i==0&&begin==1){
				continue;
			}
			sum+=i*fac(begin-1)+i*fac(n-begin);
			dfs(n,begin+1,sum);
			sum-=i*fac(begin-1)+i*fac(n-begin);
		}
	}
	else {
		for(int i=0;i<=9;i++){
			if(i==0&&begin==1){
				continue;
			}
			sum+=i*fac(begin-1);
			dfs(n,begin+1,sum);
			sum-=i*fac(begin-1);
		}
	}
	return 0;
}
int main(){
	int n;
	cin>>n;
	dfs(n,1,0);
	for(std::set<int>::iterator it=ans.begin();it!=ans.end();it++){
		cout<<*it<<endl;
	}
	return 0;
}
