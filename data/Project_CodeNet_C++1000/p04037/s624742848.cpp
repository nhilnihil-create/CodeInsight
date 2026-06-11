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
int n,a[maxn];

inline int rd(){
	int ret=0,af=1; char gc=getchar();
	while(gc < '0' || gc > '9'){ if(gc=='-') af=-af; gc=getchar(); }
	while(gc >= '0' && gc <= '9') ret=ret*10+gc-'0',gc=getchar();
	return ret*af;
}

inline bool cmp(int a,int b){ return a > b; }

int main(){
	n=rd();
	go(i,n+1,1) a[i]=rd();
	sort(a+1,a+n+1,cmp);
	int i=0;
	while(a[i+1] >= i+1) i++;
	int j=i;
	while(a[j+1] >= i && j+1 <= n) j++;
	if((j-i)%2 || (a[i]-i)%2) puts("First");
	else puts("Second");
	return 0;
}//Faze
