#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
vector<int>a;int mn=1,mx;
void solve(s64 n)
{
	if(!n)return ;
	if(n%2)
	{
		solve(n/2);
		a.push_back(++mx);
	}
	else
	{
		solve(n-1);
		a.push_back(--mn);
	}
}

int main()
{
	//freopen("1.in","r",stdin);
	s64 n;cin>>n;
	solve(n);
	printf("%d\n",a.size()*2);
	for(auto i:a)printf("%d ",i-mn+1);
	rep(i,1,a.size())printf("%d ",i);
}