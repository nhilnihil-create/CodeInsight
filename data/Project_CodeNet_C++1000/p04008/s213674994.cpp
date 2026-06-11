#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 200020
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,m,fs[M],nt[M],ans,to[M],p[M],tmp,D[M];
void link(int x,int y){nt[tmp]=fs[x],fs[x]=tmp,to[tmp++]=y;}
void DFS(int x){
	D[x]=1;
	for(int i=fs[x];i!=-1;i=nt[i]){
		DFS(to[i]),D[x]=max(D[x],D[to[i]]+1);
	}
	if(D[x]==m&&p[x]!=1) ans++,D[x]=0;
}
int main(){
	n=read(),m=read(),p[1]=read(),memset(fs,-1,sizeof(fs));
	for(int i=2;i<=n;i++) p[i]=read(),link(p[i],i);
	for(int i=fs[1];i!=-1;i=nt[i]) DFS(to[i]);
	printf("%d\n",ans+(p[1]!=1));
	return 0;
}