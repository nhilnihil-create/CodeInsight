#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 100020
#define INF 100000000000000000ll
using namespace std;
LL read(){
	LL nm=0,fh=1; LL cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL n,x,F[3],G[3];
int main(){
	n=read(),G[1]=G[2]=-INF;
	while(n--){
		x=read(),F[0]=G[0]+x,F[1]=G[1]-x,F[2]=G[2]+x;
		if(x<0) F[2]=max(F[1],F[2]),F[1]=max(F[1],F[0]);
		F[0]=max(F[0],F[1]),F[1]=max(F[1],F[2]);
		G[0]=F[0],G[1]=F[1],G[2]=F[2];
	}
	printf("%lld\n",F[0]);
	return 0;
}