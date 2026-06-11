#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int a[maxn],n;

int main()
{
	n=read(); rep(i,1,n) a[i]=read(); sort(a+1,a+n+1);
	if(a[1]+1<a[n]) return puts("No"),0;
	if(a[1]==a[n])
	{
		if(a[1]==n-1||(n/a[1])>=2) puts("Yes");
		else puts("No");
	}
	else
	{
		int f=0,n1,n2;
		rep(i,1,n) if(a[i]!=a[1]) {f=i-1; break;}
		n1=f; n2=n-f;
		if(n2>=(a[n]-n1)*2&&a[n]>=(n1+1)) puts("Yes"); else puts("No");
	}
	return 0;
}