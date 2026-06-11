#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 400020
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,m,L,R,md,t[M],ans,p[M],t1,t2;
bool solve(int x){
	t1=0,t2=(n<<1);
	for(int i=1;i<=m;i++) p[i]=(t[i]>=x);
	for(int i=2;i<=n;i++) if(p[i]==p[i-1]) t1=i;
	for(int i=m-1;i>=n;i--) if(p[i]==p[i+1]) t2=i;
	if(t1==n||t2==n) return p[n]>0;
	if(t1>1&&t2<m&&p[t1]==p[t2]) return p[t1]>0;
	if(t2-n<n-t1) return p[t2]>0;
	if(t2-n>n-t1) return p[t1]>0;
	return (p[n]^(n&1)^1)>0;
}
int main(){
	n=read(),L=1,R=n,R<<=1,R--,m=R;
	for(int i=1;i<=n+n-1;i++) t[i]=read();
    while(L<=R){
    	md=(L+R>>1);
    	if(!solve(md)) R=md-1;
		else L=md+1,ans=md;
	}
	printf("%d\n",ans);
	return 0;
}