#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

#define Rep(b, e, i) for(int i = b; i <= e; i++)
#define Repr(e, b, i) for(int i = e; i >= b; i--)
#define rep(n, i) Rep(0, n-1, i)
#define repr(n, i) Repr(n-1, 0, i)
#define all(v) (v).begin(), (v).end()
#define pb(x) push_back(x)
#define uniq(x) (x).erase(unique(all(x)),(x).end())

const int MAX = 5050;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<29;
const int MOD = 1000000007;

int N, K;
bool dp[MAX][MAX];
vector <int> v;

bool check(int x) {
    int n = (int)v.size();
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    rep(n, i) rep(K, j) {
        dp[i+1][j] = dp[i][j] || dp[i+1][j];
        if (j+v[i] < K && dp[i][j] && x != i) dp[i+1][j+v[i]] = true;
    }
    rep(K, j) if (dp[n][j] && j + v[x] >= K) return true;
    return false;
}

void solve(void){
    cin >> N >> K;
    rep(N, i) {
        int d; cin >> d;
        if (d < K) {
            v.pb(d);
        }
    }
    sort(all(v));
    int ok = (int)v.size(), ng = -1;
    while(abs(ok-ng)>1) {
        int mid = (ok + ng) / 2;
        if (check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ng+1 << endl;
}

int main(void){
  solve();
  //cout << "yui(*-v・)yui" << endl;
  return 0;
}
