#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int fir[100010],dis[400010],nxt[400010],id;
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
bool col[100010],vis[100010],yes;int cnt;
void dfs(int x){
	vis[x]=1;++cnt;
	for(int i=fir[x];i;i=nxt[i]){
		if(!vis[dis[i]])col[dis[i]]=!col[x],dfs(dis[i]);
		else if(col[dis[i]]==col[x])yes=1;
	}
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),a,b;
	for(int i=1;i<=m;++i)a=gi(),b=gi(),link(a,b),link(b,a);
	int c1=0,c2=0,c3=0;
	for(int i=1;i<=n;++i)
		if(!vis[i]){
			yes=0,cnt=0,dfs(i);
			if(cnt==1)++c3;
			else if(yes)++c1;
			else ++c2;
		}
	printf("%lld\n",1ll*c2*c2+1ll*(c1+c2)*(c1+c2)+2ll*c3*n-1ll*c3*c3);
	return 0;
}
