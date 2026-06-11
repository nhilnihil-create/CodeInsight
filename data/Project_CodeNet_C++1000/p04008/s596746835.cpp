#include<bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;i++)
using namespace std;
int n,m,ans,k;
vector<int>g[100500];
int mx[100500],dep[100500],a[100500];
void dfs(int u,int fa){
    mx[u]=max(mx[u],dep[u]);
    for (auto v:g[u]){
        if (v==fa) continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
        mx[u]=max(mx[u],mx[v]); 
    }
    if (mx[u]-dep[u]>=k-1&&u!=1&&a[u]!=1) mx[u]=0,ans++; 
}
int main(){
    scanf("%d%d",&n,&k);
    rep(i,1,n) scanf("%d",&a[i]);
    if (a[1]!=1) ans++,a[1]=1;
    rep(i,2,n) g[a[i]].push_back(i);
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}