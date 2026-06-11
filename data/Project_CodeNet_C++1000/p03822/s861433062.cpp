#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = (int)1e5 + 9;
vector<int> T[N];
int dp[N];

void dfs(int u){
    dp[u]=0;
    vector<int> dps;
    for(auto x : T[u]){
        dfs(x);
        dps.push_back(dp[x]);
    }
    int ad = 1;
    sort(dps.begin(), dps.end());
    reverse(dps.begin(), dps.end());
    for(auto x : dps){
        dp[u]=max(dp[u],x + ad);
        ad ++ ;
    }
}

int main(){
    fastIO;
    int n;
    cin >> n;
    int p;
    for(int i = 2; i <= n; i ++ ){
        cin >> p;
        T[p].push_back(i);
    }
    dfs(1);
    cout << dp[1];
    return 0;
}