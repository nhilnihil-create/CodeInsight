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

int n,a[maxn],f,f2;

inline bool cmp(int a,int b){return a>b;}

int main()
{
	n=read(); rep(i,1,n) a[i]=read(); sort(a+1,a+n+1,cmp);
	rep(i,1,(n+1)) if(a[i]<i) {f=i-1; break;}
	rep(i,f,n) if(a[i]>=f) f2++; else break;
	if((a[f]-f)%2==1||f2%2==0) puts("First");
	else puts("Second");
	return 0;
}