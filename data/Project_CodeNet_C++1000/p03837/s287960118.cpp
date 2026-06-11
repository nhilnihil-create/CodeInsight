#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<ll,ll>;
using graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll dp[105][105];

int main(){
    int N,M;
    cin>>N>>M;
    rep(i,105){
        rep(j,105) if(i!=j) dp[i][j]=INF;
    }
    vector<vector<bool>> edge(N,vector<bool>(N));
    rep(i,M){
        ll a,b,c;
        cin>>a>>b>>c;
        dp[a-1][b-1] = c;
        dp[b-1][a-1] = c;
        edge[a-1][b-1] = true;
        edge[b-1][a-1] = true;
    }
    vector<vector<bool>> done(N,vector<bool>(N));
    rep(k,N){
        rep(i,N){
            rep(j,N) {
                if(chmin(dp[i][j],dp[i][k]+dp[k][j])) done[i][j] = true;
            }
        }
    }
    ll ans = 0;
    rep(i,N){
        rep(j,N){
            if(edge[i][j]&&done[i][j]) ans++;
        }
    }
    cout<<ans/2<<endl;
}