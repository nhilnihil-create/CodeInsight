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

int a[maxn],b[maxn],c1,c2,n;

int main()
{
	n=read(); rep(i,1,n) a[i]=read(),b[i]=a[i];
	sort(b+1,b+n+1);
	rep(i,1,n)
	{
		int x=lower_bound(b+1,b+n+1,a[i])-b;
		if(i%2==1&&(x%2==0)) c1++;
		else if(i%2==0&&(x%2==1)) c2++;
	}
	cout<<max(c1,c2);
	return 0;
}