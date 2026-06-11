/*Program from Luvwgyx*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=1e5+10;
const int maxm=2e5+10;
struct node{int to,nxt;}e[maxm<<1];
int tot,p,c,d,flag,head[maxn],deg[maxn],vis[maxn],col[maxn];
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(ll x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
void write(ll x){print(x);puts("");}
void add(int u,int v){e[++tot].to=v;e[tot].nxt=head[u];head[u]=tot;deg[u]++;}
void insert(int u,int v){add(u,v);add(v,u);}
void dfs(int x){
    vis[x]=1;
    for(int i=head[x],v=e[i].to;i;i=e[i].nxt,v=e[i].to){
        if(!vis[v])col[v]=col[x]^1,dfs(v);
        else if(col[v]^col[x]^1)c-=flag,d+=flag,flag=0;
    }
}
int main(){
    int n=read(),m=read();
    for(int i=1;i<=m;i++)insert(read(),read());
    for(int i=1;i<=n;i++){
        if(!deg[i])p++;
        else if(!vis[i])flag=1,c++,dfs(i);
    }write(1ll*p*n+1ll*p*(n-p)+1ll*d*d+1ll*c*2*(d+c));
    return 0;
}
