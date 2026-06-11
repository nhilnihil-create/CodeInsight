#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

const ll mod = 1e9 + 7;
ll dp[5010][5010];

int main() {
    int n;
    string s;
    cin >> n >> s;
    int m = s.length();

    dp[0][0] = 1;
    REP(i,n) REP(j,n){
        dp[i+1][j+1] = (dp[i+1][j+1] + 2 * dp[i][j]) % mod;
        dp[i+1][max(0,j-1)] = (dp[i+1][max(0,j-1)] + dp[i][j]) % mod;
    }

    // REP(i,n+1){
    //     REP(j,n+1) cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    ll ans = dp[n][m];
    // cout << ans << endl;
    REP(_,m){
        ans = (ans * 500000004) % mod;
    }

    cout << ans << endl;

    return 0;
}