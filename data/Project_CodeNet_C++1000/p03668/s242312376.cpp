#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
const int maxn=100000+10;
int h[maxn],go[maxn*2],nxt[maxn*2];
int i,j,k,l,t,n,m,tot;
void add(int x,int y){
    go[++tot]=y;
    nxt[tot]=h[x];
    h[x]=tot;
}
int dfs(int x,int y){
    int l=0,t=h[x];
    while (t){
        if (go[t]!=y) l^=dfs(go[t],x)+1;
        t=nxt[t];
    }
    return l;
}
int main(){
    scanf("%d",&n);
    fo(i,1,n-1){
        scanf("%d%d",&j,&k);
        add(j,k);add(k,j);
    }
    if (dfs(1,0)) printf("Alice\n");else printf("Bob\n");
}