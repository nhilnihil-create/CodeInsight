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

int a[maxn],n,L,f;

int main()
{
	n=read(),L=read(); rep(i,1,n) a[i]=read();
	if(n==1) return puts("Possible"),0;
	rep(i,1,(n-1)) if(a[i]+a[i+1]>=L) {f=i; break;}
	if(!f) puts("Impossible");
	else
	{
		puts("Possible");
		rep(i,1,(f-1)) printf("%d\n",i);
		per(i,(n-1),(f+1)) printf("%d\n",i); printf("%d\n",f);
	}
	return 0;
}