#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x,da;
int a[225];
void dfs(int l,int r){
	if(l%r==0){
		da+=(l*2)-r;
		return ;
	}
	da+=(l-l%r)*2;
	dfs(r,l%r);
}
signed main(){
	cin>>n>>x;
	da=n;
	if(n-x>=x){
		dfs(n-x,x);
	}
	else dfs(x,n-x);
	cout<<da;
}