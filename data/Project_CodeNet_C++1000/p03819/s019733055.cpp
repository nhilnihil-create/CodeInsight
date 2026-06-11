#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 300020
using namespace std;
int read(){
	int nm=0,fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,m,c[M],od[M],L[M],R[M];
void add(int ps,int x){for(int k=ps;k<=m;k+=(k&-k)) c[k]+=x;}
int sum(int ps){int tt=0;for(int k=ps;k;k-=(k&-k)) tt+=c[k]; return tt;}
void write(int x){if(x>9) write(x/10); putchar(x%10+'0');}
bool cmp(int x,int y){return R[x]-L[x]<R[y]-L[y];}
void check(int x){add(L[x],1),add(R[x]+1,-1);}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++) L[i]=read(),R[i]=read(),od[i]=i;
	sort(od+1,od+n+1,cmp);
	for(int i=1,now=1,ans,ps;i<=m;i++,write(ans),putchar('\n')){
		for(;now<=n&&R[od[now]]-L[od[now]]<i;now++) check(od[now]);
		for(ans=n-now+1,ps=i;ps<=m;ps+=i) ans+=sum(ps);
	}
	return 0;
}