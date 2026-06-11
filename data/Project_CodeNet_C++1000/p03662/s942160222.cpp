#include<iostream>
#include<cstdio>
using namespace std;
int n,a,b,cnt=0,id=0,ne[100005],in[100005],out[100005],cnt1,cnt2,fa[100005][20],len[100005];
struct node{
    int v,next;
}edge[400005];
inline int read(){
	char c=getchar();
	int x=0;
	for(;c>'9'||c<'0';) c=getchar();
	for(;c>='0'&&c<='9';){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
inline void add(int u,int v){
    edge[cnt]={v,ne[u]};
    ne[u]=cnt++;
    edge[cnt]={u,ne[v]};
    ne[v]=cnt++;
}
inline void dfs(int cur,int pre,int d){
    fa[cur][0]=pre;
    len[cur]=d;
    for(int i=1;i<20;i++)
        fa[cur][i]=fa[fa[cur][i-1]][i-1];
    in[cur]=++id;
    for(int i=ne[cur];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(v==pre) continue;
        dfs(v,cur,d+1);
    }
    out[cur]=id;
}
int main(){
	n=read();
    for(int i=0;i<100005;i++) ne[i]=-1;
    for(int i=1;i<n;i++){
    	a=read(),b=read();
        add(a,b);
    }
    dfs(1,0,0);
    int tmp=(len[n]-1)>>1,now=n;
    for(int i=0;i<20;i++)
        if(tmp>>i&1) now=fa[now][i];
    cnt1=n-(out[now]-in[now]+1)-len[n]/2-1,cnt2=out[now]-in[now]+1-tmp-1;
    if(len[n]&1){
        if(cnt1<=cnt2) puts("Snuke");
        else puts("Fennec");
        return 0;
    }
    if(cnt2>cnt1) puts("Snuke");
    else puts("Fennec");
    return 0;
}