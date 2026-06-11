#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,a[N],now;
bool cmp(int x,int y){return x>y;}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i)if(a[i+1]<i+1){
		for(;a[i+now+1]==i;++now);
		if(((a[i]-i)&1) || (now&1)) cout<<"First";
		else cout<<"Second";
		return 0;
	}
	return 0;
}