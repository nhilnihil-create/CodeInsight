#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#define rep(i,x,y) for(int i=x;i<=y;++i)
using namespace std;
const int Maxn=3e5+5;
const long long Inf=1e16;
int n,a[Maxn];
long long ans,f[Maxn],g[Maxn];
priority_queue<int> pq;
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
	//freopen("std.in","r",stdin);
	cin>>n;ans=-Inf;
	for(int i=1;i<=3*n;i++)
	{
		cin>>a[i];
		if(i<=n)
		{
			f[i]=f[i-1]+a[i];
			q.push(a[i]);
		}
		else if(a[i]>q.top())
		{
			f[i]=f[i-1]-q.top()+a[i];
			q.pop();
			q.push(a[i]);
		}
		else f[i]=f[i-1];
	}
	for(int i=3*n;i>=1;i--)
	{
		if(i>2*n)
		{
			g[i]=g[i+1]+a[i];
			pq.push(a[i]);
		}
		else if(a[i]<pq.top())
		{
			g[i]=g[i+1]-pq.top()+a[i];
			pq.pop();
			pq.push(a[i]);
		}
		else g[i]=g[i+1];
	} 
	for(int i=n;i<=2*n;i++)
		ans=max(ans,f[i]-g[i+1]);
	cout<<ans;
	return 0;
}
