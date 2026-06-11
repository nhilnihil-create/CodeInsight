#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define N 100010
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int n,a[N],h[N],num=0,du[N],fa[N];
struct edge{
	int to,next;
}data[N<<1];
bool dfs(int x){
	if(du[x]==1) return 1;
	ll sum=0;int mx=0;
	for(int i=h[x];i;i=data[i].next){
		int y=data[i].to;if(fa[x]==y) continue;
		fa[y]=x;if(!dfs(y)) return 0;mx=max(mx,a[y]);sum+=a[y];
	}if(a[x]>sum) return 0;if(a[x]==sum) return 1;
	ll res= mx>sum-mx?sum-mx:sum/2;//内部交流最多res对
	if(sum-a[x]>res||a[x]-(sum-a[x])<0) return 0;
	a[x]-=sum-a[x];return 1; 
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<n;++i){
		int x=read(),y=read();du[x]++;du[y]++;
		data[++num].to=y;data[num].next=h[x];h[x]=num;
		data[++num].to=x;data[num].next=h[y];h[y]=num;
	}if(n==2){puts(a[1]==a[2]?"YES":"NO");return 0;}
	for(int i=1;i<=n;++i)
		if(du[i]!=1){
			if(!dfs(i)) puts("NO");
			else puts(a[i]?"NO":"YES");return 0;
		}
}
