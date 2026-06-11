#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
#include<stack>
#include<algorithm>
#define rg register
#define ll long long
#define LDB long double
#define ull unsigned long long
#define view(i,x) for(rg int i=hd[x];i!=-1;i=e[i].nt)
#define go(i,x,a) for(rg int i=a;i<x;i++)
#define inf 0x3f3f3f3f
#define INF 0x7fffffff
using namespace std;

const int maxn=1e5+5;
int n,m,w[maxn],d[maxn],a[maxn];
ll ss=0,des,tt;

inline int rd(){
	int ret=0,af=1; char gc=getchar();
	while(gc < '0' || gc > '9'){ if(gc=='-') af=-af; gc=getchar(); }
	while(gc >= '0' && gc <= '9') ret=ret*10+gc-'0',gc=getchar();
	return ret*af;
}

int main(){
	#ifndef ONLINE_JUDGE
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	#endif
	n=rd();
	go(i,n+1,1) w[i]=rd(),ss=ss+w[i]; w[n+1]=w[1];
	go(i,n+1,1) d[i]=w[i+1]-w[i]; d[n+1]=d[1];
	ll ons=1ll*n*(1+n)/2;
	if(ss%ons != 0){ puts("NO"); return 0; }
	ll dep=ss/ons; int fl=0;
	go(i,n+2,1){
		a[i]=(dep-d[i])/n;
		if(a[i] < 0) a[i]=0;
		if((dep-d[i])%n != 0) fl=1;
		if(i >= 2) des=des+tt,des=des+a[i-1],tt=tt+a[i-1];
	}
	if(fl){ puts("NO"); return 0; }
	go(i,n+1,1){
		des-=1ll*n*a[i]; tt-=a[i];
		if(i > 1) des=des+a[i-1],tt=tt+a[i-1];
		if(des+1ll*a[i]*n != w[i]){ fl=1; break; }
		des=des+tt;
	}
	if(fl) puts("NO");
	else puts("YES");
	return 0;
}//Faze
