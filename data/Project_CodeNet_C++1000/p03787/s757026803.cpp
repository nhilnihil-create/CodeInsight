#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
ll int MOD=998244353;
#define INF 2*1e9
#define N 310000
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");
int par[N],grade[N];
void init(int n){
    rep2(i,1,n){
        par[i]=i;
        grade[i]=0;
    }
}
int root(int x){
    return par[x]==x?x:par[x]=root(par[x]);
}
bool same(int x,int y){
    return root(x)==root(y);
}
void unite(int x,int y){
    x=root(x); y=root(y);
    if(x==y)return;
    if(grade[x]<grade[y]){
        par[x]=y;
    }
    else{
        par[y]=x;
        if(grade[x]==grade[y]) grade[x]++;
    }
}
ll int n,m,color[N];
vector<int> v[N];
int dfs(int a,int b){
    if(color[a]==b) return 1;
    if(color[a]!=0&&color[a]!=b) return 0;
    color[a]=b;
    b*=-1;
    bool ans=true;
    rep(i,v[a].size()){
        ans=ans&dfs(v[a][i],b);
    }
    return ans;
}
main(){
    cin>>n>>m;
    init(n);
    rep(i,m){
        int u,w;
        cin>>u>>w;
        v[u].pb(w);v[w].pb(u);
        unite(u,w);
    }
    bool used[N]={};
    ll int a=0,b=0,c=0;
    rep2(i,1,n){
        int r=root(i);
        if(used[r])continue;
        used[r]=1;
        if(grade[r]==0){
            a++; continue;
        }
        if(dfs(r,1)) b++;
        else c++;
    }
    cout<<((2*n-1)*a-a*(a-1)+2*b*b+2*b*c+c*c);
    return 0;
}

