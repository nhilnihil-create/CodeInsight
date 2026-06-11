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

const int maxn=105;
int n,a[maxn],q[maxn],tax[maxn],tq[maxn];

inline int rd(){
	int ret=0,af=1; char gc=getchar();
	while(gc < '0' || gc > '9'){ if(gc=='-') af=-af; gc=getchar(); }
	while(gc >= '0' && gc <= '9') ret=ret*10+gc-'0',gc=getchar();
	return ret*af;
}

inline bool cmp(int a,int b){ return a > b; }

inline bool check(){
	go(i,n+1,1) tax[a[i]]++;
	int tl=0,len=a[1]-1;
	q[++tl]=a[1];
	while(len > 0){
		q[tl+1]=q[tl]-1; tl++;
		len-=2;
	}
	go(i,tl,1){
		if(tax[q[i]] < 2) return 0;
		tq[q[i]]+=2;
	}
	if(tax[q[tl]] < (len == 0 ? 2 : 1)) return 0;
	tq[q[tl]]+=(len == 0 ? 2 : 1);
	q[tl]++;
	go(i,n+1,1)
		if(a[i] < q[tl]){
			if(tq[a[i]] == 0) return 0;
			tq[a[i]]--;
		}
	return 1;
}

int main(){
	n=rd();
	go(i,n+1,1) a[i]=rd();
	sort(a+1,a+n+1,cmp);
	if(check()) puts("Possible");
	else puts("Impossible");
	return 0;
}//Faze
