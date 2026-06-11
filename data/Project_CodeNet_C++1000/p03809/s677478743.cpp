#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
const int MAXN=1e5+5;

int n;
ll a[MAXN];
vector<int> E[MAXN];

inline void err(){puts("NO"); exit(0);}

void dfs(int u,int fa=0){
    if(E[u].size()==1) return;
    ll sum=0,mx=0;
    for(int i=0;i<(int)E[u].size();i++){
        int v=E[u][i];
        if(v==fa) continue;
        dfs(v,u);
        sum+=a[v];
        mx=max(mx,a[v]);
    }
    if(sum<a[u]||sum>2*a[u]) err();
    if(mx>a[u]) err();
    a[u]=2*a[u]-sum;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    if(n==2){
        if(a[1]!=a[2]) err();
        puts("YES");
        exit(0);
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    int st=1;
    for(;E[st].size()==1;st++);
    dfs(st);
    if(!a[st]) puts("YES");
    else puts("NO");
}
