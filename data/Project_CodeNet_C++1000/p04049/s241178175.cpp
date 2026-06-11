#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int W[4010],n,K,fir[4010],dis[8010],nxt[8010],id;
void link(int a,int b){
	nxt[++id]=fir[a],fir[a]=id,dis[id]=b;
	nxt[++id]=fir[b],fir[b]=id,dis[id]=a;
}
int DFS(int x,int k,int fa=-1){
	if(k<0)return 0;
	int ret=x<=n;
	for(int i=fir[x];i;i=nxt[i])if(dis[i]!=fa)ret+=DFS(dis[i],k-1,x);
	return ret;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),K=gi();int u,v;
	for(int i=1;i<n;++i)u=gi(),v=gi(),link(u,i+n),link(i+n,v);
	int ans=0;
	for(int i=1;i<n+n;++i)ans=std::max(ans,DFS(i,K));
	printf("%d\n",n-ans);
	return 0;
}
