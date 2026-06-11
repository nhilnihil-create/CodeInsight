#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;

int n,rt,tot,deg[maxn];
int A[maxn],now[maxn],pre[maxn*2],son[maxn*2];

int read() {
    int x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
    return x*f;
}

void add(int a,int b) {
    pre[++tot]=now[a];
    now[a]=tot,son[tot]=b;
}

ll dfs(int fa,int u) {
    if(deg[u]==1)return A[u];
    ll remain=A[u]<<1;
    for(int p=now[u],v=son[p];p;p=pre[p],v=son[p])
        if(v!=fa) {
            ll tmp=dfs(u,v);
            if(tmp>A[u]) {puts("NO");exit(0);}
            remain-=tmp;
        }
    if(remain<0||remain>A[u]) {puts("NO");exit(0);}
    return remain;
}

int main() {
    n=read();
    for(int i=1;i<=n;i++)
        A[i]=read();
    if(n==2) {
        if(A[1]==A[2])puts("YES");
        else puts("NO");return 0;
    }
    for(int i=1;i<n;i++) {
        int x=read(),y=read();
        add(x,y),add(y,x);deg[x]++,deg[y]++;
        if(deg[x]>1)rt=x;if(deg[y]>1)rt=y;
    }
    if(dfs(0,rt))puts("NO");
    else puts("YES");
    return 0;
}