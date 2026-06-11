#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7; bool fl[N];
int n,m,q,pos[N],que[N]; long long k,w[N],val[N];
inline long long read(){
	long long num=0; char t='+',g=getchar(); while(g<48||57<g) t=g,g=getchar();
	while(47<g&&g<58) num=(num<<1)+(num<<3)+g-48,g=getchar(); if(t=='-') return 0-num; return num;
}
inline void find(int u){
	que[++que[0]]=u,fl[u]=1; if(!fl[pos[u]]) find(pos[u]);
}
inline void getans(){
	int z=k%que[0]; for(int i=1;i<=que[0];i++) pos[que[i]]=que[(i+z-1)%que[0]+1];
}
int main(){
	n=read(); for(int i=1;i<=n;i++) w[i]=read(),pos[i]=i;
	m=read(),k=read(); for(int i=1;i<=m;i++) q=read(),swap(pos[q],pos[q+1]);
	for(int i=2;i<=n;i++) if(!fl[i]) que[0]=0,find(i),getans();
	for(int i=2;i<=n;i++) val[i]=w[i]-w[i-1]; long long vt=w[1]; printf("%lld\n",vt);
	for(int i=2;i<=n;i++) vt=vt+val[pos[i]],printf("%lld\n",vt);
	return 0;
}