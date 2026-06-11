#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=a;i<=b;++i)
#define rpd(i,a,b) for(register int i=a;i>=b;--i)
#define rep1(i,x) for(register int i=head[x];i;i=nxt[i])
typedef long long ll;
const int N=2000+5;
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,tot,K,ans=1e9;int head[N],nxt[N<<1],to[N<<1],dep[N];
void add(int u,int v){nxt[++tot]=head[u];head[u]=tot;to[tot]=v;}
void dfs(int x,int fa,int now){dep[x]=now;rep1(i,x){int p=to[i];if(p==fa)continue;dfs(p,x,now+1);}}
int main(){
	n=read();K=read();
	rep(i,1,n-1){int u=read(),v=read();add(u,v);add(v,u);}
	if(K&1){
		rep(i,1,n){
			rep1(j,i){
				int p=to[j];if(p>i)continue;
				int sum=0;dfs(p,i,0);dfs(i,p,0);
				rep(t,1,n)if(dep[t]>K/2)sum+=1;
				ans=min(ans,sum);
			}
		}
	}
	else{
		rep(i,1,n){
			int sum=0;dfs(i,0,0);
			rep(j,1,n)if(dep[j]>K/2)sum+=1;
			ans=min(ans,sum);
		}
	}
	return printf("%d\n",ans),0;
}