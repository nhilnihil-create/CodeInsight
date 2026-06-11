#include <iostream>
#include <vector>
using namespace std;
const int N = 2002;
int n,k;
vector<int> g[N];
int dep[N],ans,res;

void dfs(int u,int p){
    if(dep[u]<=k/2)ans++;
    for(auto v: g[u]) {
        if(p==v)continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
}

int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(k%2==0) {
        for(int i=1;i<=n;i++){
            ans=0; dep[i]=0; dfs(i,i); res=max(res,ans);
        }
    } else {
        for(int u=1;u<=n;u++){
            for(auto v: g[u]) {
                ans=0;
                dep[u]=0; dfs(u,v);
                dep[v]=0; dfs(v,u);
                res=max(res,ans);
            }
        }
    }
    printf("%d\n", n-res);
}