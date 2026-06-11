#include<bits/stdc++.h>
#define rint register int
#define ll long long 
using namespace std;
struct node{
	int to,next;
}e[1011000];
int fa[1010100],tot,h[1010100],n,k,ans,dep[1011000];
inline void add(int from,int to){e[++tot].next=h[from];h[from]=tot;e[tot].to=to;}
inline void DFS(int now) {
	int Max=-1;
	for(rint i=h[now];i;i=e[i].next){
		int to=e[i].to;DFS(to);
		Max=max(Max,dep[to]);
	}
	dep[now]=Max+1;
	if(now==1) return ;
	if(dep[now]>=k-1&&fa[now]!=1) ans++,dep[now]=-1;
}
int main(){
	cin>>n>>k;
	for(rint i=1;i<=n;++i) cin>>fa[i];
	if(fa[1]!=1) ans++;
	for(rint i=2;i<=n;++i) add(fa[i],i);
	DFS(1);
	cout<<ans;
	return 0;
}