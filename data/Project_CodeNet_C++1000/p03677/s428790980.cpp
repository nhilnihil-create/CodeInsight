#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 200020
using namespace std;
namespace IO{
	const int BS=(1<<21)+3; LL Top=0; char Buffer[BS],*HD,*TL,SS[20];
	char Getchar(){if(HD==TL){TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);} return (HD==TL)?EOF:*HD++;}
	int read(){
		int nm=0; char cw=Getchar(); for(;!isdigit(cw);cw=Getchar());
		for(;isdigit(cw);cw=Getchar()) nm=nm*10+(cw-'0'); return nm;
	}
} using namespace IO;
int n,m,dt[M]; LL tot,s[M],ans;
int main(){
	n=read(),m=read();
	for(register int last=read(),i=1,x;i<n;last=x,i++){
		x=read(),dt[last+2]++;
		if(last<x) dt[x+1]--,tot+=x-last,s[x+1]-=x-last-1;
		else tot+=x+m-last,dt[1]++,dt[x+1]--,s[1]+=m-last-1,s[x+1]-=m+x-last-1;
	} ans=tot;
	for(register int i=1;i<=m;i++) dt[i]+=dt[i-1],s[i]+=s[i-1]+dt[i],ans=min(ans,tot-s[i]);
	printf("%lld\n",ans); return 0;
}