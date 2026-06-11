#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
inline long long mod(long long n,long long m){return(n%m+m)%m;}
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

vector<int> edge[100010];
int dp[100010];
int color[100010];
void bfs(int vv,int dd,int cc){
    queue<pair<int,int>> q;
    q.push({vv,dd});
    while(q.size()){
        auto x=q.front(); q.pop();
        int vvv=x.first,ddd=x.second;
        if(!color[vvv]) color[vvv]=cc;
        if(dp[vvv]>=ddd) continue;
        dp[vvv]=ddd;
        for(auto to:edge[vvv]){
            q.push({to,ddd-1});
        }
    }
}
int main(){
    int n,m; cin>>n>>m;
    rep(i,m){
        int a,b; cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    int q; cin>>q;
    int v[q],d[q],c[q];
    rep(i,q) cin>>v[i]>>d[i]>>c[i];
    rep(i,q){
        bfs(v[q-1-i],d[q-1-i],c[q-1-i]);
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",color[i]);
    }
    return 0;
}
