#include<bits/stdc++.h>
#define N 111111
using namespace std;
int n,l,T,i,V,TT,len,cnt,u,a[N],b[N],c[N],an[N],t;
struct P{
	int x,lx,id;
}p[N];
bool cmp(P a,P b){
	return a.x<b.x;
}
int main(){
	scanf("%d%d%d",&n,&l,&T);
	for(i=1;i<=n;i++)scanf("%d%d",&p[i].x,&p[i].lx),p[i].id=i;
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;i++){
		if(p[i].lx==1)b[i]=(p[i].x+T)%l;else b[i]=(p[i].x-T%l+l)%l;
	}
	for(i=2;i<=n;i++)if(p[i].lx!=p[1].lx){
		if(p[1].lx==1)len=(p[i].x-p[1].x+l)%l;
		else len=(p[1].x-p[i].x+l)%l;
		TT=T*2;
		if(TT>=len)cnt++,TT-=len;
		cnt+=TT/l;
		cnt%=n;
	}
	V=b[1];
	sort(b+1,b+n+1);
	if(p[1].lx==1)
	for(i=1;i<=n;i++)if(b[i]==V)u=i;
	if(p[1].lx==2)
		for(i=n;i;i--)if(b[i]==V)u=i;
	for(i=u;i<=n;i++)c[++t]=b[i];
	for(i=1;i<u;i++)c[++t]=b[i];
	if(p[1].lx==1)cnt=n-cnt;c[0]=c[n];
	for(i=1;i<=n;i++)an[p[i].id]=c[(i+cnt)%n];
	for(i=1;i<=n;i++)printf("%d\n",an[i]);
}