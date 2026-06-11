/*
数据不清空，爆零两行泪。
多测不读完，爆零两行泪。
边界不特判，爆零两行泪。
贪心不证明，爆零两行泪。
D P 顺序错，爆零两行泪。
大小少等号，爆零两行泪。
变量不统一，爆零两行泪。
越界不判断，爆零两行泪。
调试不注释，爆零两行泪。
溢出不 l l，爆零两行泪。
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N=100000;
int n;
int a[N+1];
int Sum[N+1],Sum0[N+1];
signed main(){
	cin>>n;
	vector<int> nepos;
	for(int i=1;i<=n;i++){
		bool ne=false;
		if(i>1){
			char c;
			cin>>c;
			if(c=='-')ne=true,nepos.pb(i);
		}
		cin>>a[i];
		if(ne)a[i]=-a[i];
		Sum[i]=Sum[i-1]+a[i];
		Sum0[i]=Sum0[i-1]+abs(a[i]);
	}
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";puts("");
	nepos.pb(n+1);
	int ans=Sum[n];
	for(int i=1;i<=n;i++)if(a[i]<0){
		int fd=*lower_bound(nepos.begin(),nepos.end(),i+1);
//		printf("fd=%lld\n",fd);
		ans=max(ans,Sum[i]-(Sum[fd-1]-Sum[i])+(Sum0[n]-Sum0[fd-1]));
	}
	cout<<ans;
	return 0;
}
/*1
3
5 - 1 - 3
*/
/*2
5
1 - 2 + 3 - 4 + 5
*/
/*3
5
1 - 20 - 13 + 14 - 5
*/