#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
const int maxn=100000+10;
int f[maxn],a[maxn],h[maxn],go[maxn],nxt[maxn];
int i,j,k,l,t,n,m,tot,top;
void add(int x,int y){
    go[++tot]=y;
    nxt[tot]=h[x];
    h[x]=tot;
}
void dfs(int x){
    int t=h[x];
    if (!t) return;
    while (t){
        dfs(go[t]);
        t=nxt[t];
    }
    top=0;
    t=h[x];
    while (t){
        a[++top]=f[go[t]];
        t=nxt[t];
    }
    sort(a+1,a+top+1);
    int i;
    fo(i,2,top)
        if (a[i]<=a[i-1]) a[i]=a[i-1]+1;
    f[x]=a[top]+1;
}
int main(){
    scanf("%d",&n);
    fo(i,2,n){
        scanf("%d",&j);
        add(j,i);
    }
    dfs(1);
    printf("%d\n",f[1]);
}