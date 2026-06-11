#include <bits/stdc++.h>
#define REP(i,s,e) for(int i=(s); i<(e);i++)
#define rep(i,n) REP(i,0,n)
#define rep1(i,n) REP(i,1,n)
#define repe(i,n) for(auto &&i:n)
#define all(v) (v).begin(),(v).end()
#define decimal fixed<<setprecision(20)
#define fastcin() cin.tie(0);ios::sync_with_stdio(false)
using namespace std;
using LL = long long;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1e9;
const LL LLINF = 1e16;

int dp[101010];

int rec(int v, Graph &G){
    if(dp[v] != -1) return dp[v];
    vector<int> tmp;
    repe(i, G[v]){
        tmp.push_back(rec(i, G));
    }
    if(tmp.empty()){
        return dp[v]=0;
    }
    sort(all(tmp));
    reverse(all(tmp));
    rep(i, tmp.size()) tmp[i]+=i;
    return dp[v]=*max_element(all(tmp))+1;
}

int main(){
    fastcin();
    int n;
    cin >> n;
    Graph G(n);
    rep1(i, n){
        int a;
        cin >> a;
        a--;
        G[a].push_back(i);
    }

    memset(dp, -1, sizeof(dp));
    cout << rec(0, G) << endl;
}