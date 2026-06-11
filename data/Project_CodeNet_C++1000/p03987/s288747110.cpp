#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
#define int long long
int n;
int a[2000020];
int l[2000020];
int r[2000020];
stack<int>st1;
stack<int>st2;
inline int read()
{
	int a=0,b=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') b=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){a=a*10+ch-'0';ch=getchar();}
	return a*b;
}
int ans;
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	a[i]=read();
	for(int i=1;i<=n;i++)
	{
		while(!st1.empty()&&a[st1.top()]>=a[i]) st1.pop();
		if(st1.empty()) l[i]=1;
		else l[i]=st1.top()+1;
		st1.push(i);
	}
	for(int i=n;i>=1;i--)
	{
		while(!st2.empty()&&a[st2.top()]>=a[i]) st2.pop();
		if(st2.empty()) r[i]=n;
		else r[i]=st2.top()-1;
		st2.push(i);
	}
	for(int i=1;i<=n;i++)
	ans+=(r[i]-i+1)*(i-l[i]+1)*a[i];
	cout<<ans;
	return 0;
}