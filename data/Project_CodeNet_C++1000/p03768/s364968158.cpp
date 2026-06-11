#include "bits/stdc++.h"
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2
#define all(x) (x).begin(),(x).end()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define debug_vec(v) cerr<<#v<<":";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
using namespace std;
int MOD = 1000000007;
int n,m,q;
int v[100010] = {0};
int d[100010] = {0};
int c[100010] = {0};
vector<int> G[100010];
int dp[100010][11] = {0};
void paint(int V,int D,int C){
    if(dp[V][D] || D < 0)return;
    dp[V][D] = C;
    for(auto x:G[V]){
        paint(x,D-1,C);
    }
    paint(V,D-1,C);
    return;
}
signed main(){

    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        G[a-1].pb(b-1);
        G[b-1].pb(a-1);
    }
    cin >> q;
    rep(i,q){
        cin >> v[i] >> d[i] >> c[i];
    }
    for(int i = q-1;i >= 0;i--){
        paint(v[i]-1,d[i],c[i]);
        // rep(i,n)cerr << color[i] << " ";
        // cerr << endl;
    }
    rep(i,n)cout << dp[i][0] << endl;

    return 0; 
}

// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://yahoo-procon2019-qual.contest.atcoder.jp/tasks/yahoo_procon2019_qual_d
// rm -r -f test;oj dl http://agc012.contest.atcoder.jp/tasks/agc012_b