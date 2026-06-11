// 基本テンプレート

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
using namespace std;

#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define int long long int

template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}

typedef pair<int, int> pii;
typedef long long ll;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
constexpr ll INF = 1001001001001001LL;
constexpr ll MOD = 1000000007LL;

const int S = 5000;
int dp[S+10][S+10];

ll mod_pow(ll x, ll n) {
    if(n == 0) return 1;
    ll res = mod_pow((x * x) % MOD, n / 2);
    if(n & 1) res = (res * x) % MOD;
    return res;
}

signed main() {
    int N; cin >> N;
    string s; cin >> s;
    int len = s.length();

    dp[0][0] = 1;
    rep(i,0,N) repq(j,0,S) {
        // add
        (dp[i+1][j+1] += dp[i][j] * 2) %= MOD;

        // delete
        (dp[i+1][max(0LL, j-1)] += dp[i][j]) %= MOD;
    }

    int pw = mod_pow(2, len);
    cout << ( dp[N][len] * mod_pow(pw, MOD-2) ) % MOD << endl;
    return 0;
}