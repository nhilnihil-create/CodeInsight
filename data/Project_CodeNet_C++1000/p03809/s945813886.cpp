#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7; bool fp,fl[N];
int n,p,w[N],len[N],val[N]; vector<int>v[N];
inline int read(){
	int num=0; char g=getchar(); while(g<48||57<g) g=getchar();
	while(47<g&&g<58) num=(num<<1)+(num<<3)+g-48,g=getchar(); return num;
}
inline void find(int u){
	long long res=0; int cnt=0,maxn=0; fl[u]=1;
	for(int i=0;i<len[u];i++){
		int x=v[u][i]; if(fl[x]) continue; find(x),cnt++,res+=val[x],maxn=max(maxn,val[x]);
	}
	if(!cnt) val[u]=w[u];
	else{
		val[u]=w[u]*2-res; long long c=w[u]-val[u]; if(val[u]<0||w[u]>res) fp=1; if(res-maxn<c) fp=1;
	}
}
int main(){
	n=read(); int u,t;
	for(int i=1;i<=n;i++) w[i]=read(); if(n==2) {if(w[1]==w[2]) puts("YES"); else puts("NO"); return 0;}
	for(int i=1;i<n;i++) u=read(),t=read(),v[u].push_back(t),v[t].push_back(u),len[u]++,len[t]++;
	for(int i=1;i<n;i++) if(len[i]>1) p=i; find(p); if(val[p]) fp=1;
	if(fp) puts("NO"); else puts("YES");
	return 0;
}