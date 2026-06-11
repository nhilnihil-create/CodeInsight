#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 100020
using namespace std;
LL read(){
	LL nm=0,fh=1; LL cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL n,p[M],G[M],F[M],ans;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(LL i=1;i<=n;i++){
		p[i]=read();
		if(i>1&&p[i]>0&&p[i-1]>0) p[i-1]+=p[i],i--,n--;
	}
	for(LL i=1;i<=n;i++) G[i]=G[i-1]+p[i],F[i]=F[i-1]+abs(p[i]); ans=G[n];
//	for(LL i=1;i<=n;i++) printf("I = %lld    p = %lld   G = %lld   F = %lld \n",i,p[i],G[i],F[i]);
	for(LL i=2;i<=n;i++) if(p[i-1]<0) ans=max(ans,G[i-1]-p[i]+F[n]-F[i]);
	printf("%lld\n",ans);
	return 0;
}