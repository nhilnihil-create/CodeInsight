#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI pair<int,int>
const int maxm=1e6+5;
struct Node{
    int a,b;
}e[maxm];
vector<int>g[maxm];
int n,k;
int temp;
int limit;
void dfs(int x,int fa,int dep){
    if(dep>limit)return ;
    temp++;
    for(int v:g[x]){
        if(v==fa)continue;
        dfs(v,x,dep+1);
    }
}
int solve1(int x){
    temp=0;
    dfs(x,x,0);
    return n-temp;
}
int solve2(int p){
    temp=0;
    dfs(e[p].a,e[p].b,0);
    dfs(e[p].b,e[p].a,0);
    return n-temp;
}
signed main(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        e[i]={a,b};
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans=1e9;
    limit=k/2;
    if(k%2==0){
        for(int i=1;i<=n;i++){
            int t=solve1(i);
            ans=min(ans,t);
        }
    }else{
        limit=k/2;
        for(int i=1;i<n;i++){
            int t=solve2(i);
            ans=min(ans,t);
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*

*/
