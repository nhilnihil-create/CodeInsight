//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n,m,q; cin>>n>>m;
    vector<vector<int>> path(n),dp(n,vector<int>(11,0));
    rep(i,m){
        int a,b; cin>>a>>b;
        a--; b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    cin>>q;
    vector<vector<int>> Q(q,vector<int>(3,0));
    rep(i,q)rep(j,3){
        cin>>Q[i][j];
        if(j==0) Q[i][j]--;
    }
    int v,d;
    for(int i=q-1;i>=0;i--){
        queue<pp> que;
        v=Q[i][0]; d=Q[i][1];
        if(d==0){
            if(dp[v][d]==0) dp[v][d]=Q[i][2];
            continue;
        }
        if(dp[v][d]==0){
            dp[v][d]=Q[i][2];
            que.push(mk(v,d));
        }
        while(!(que.empty())){
            int u,k;
            tie(u,k)=que.front();
            que.pop();
            if(dp[u][k-1]==0){
                dp[u][k-1]=Q[i][2];
                if(k>1) que.push(mk(u,k-1));
            } 
            for(auto to:path[u]){
                if(dp[to][k-1]==0){
                    dp[to][k-1]=Q[i][2];
                    if(k>1) que.push(mk(to,k-1));
                }
            }
        }
    }
    rep(i,n) printf("%d\n",dp[i][0]);
}