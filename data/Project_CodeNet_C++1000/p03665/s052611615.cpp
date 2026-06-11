#define _USE_MATH_DEFINES
#include  <iostream>
#include  <algorithm>
#include  <climits>
#include  <vector>
#include  <string>
#include  <cstring>
#include  <stack>
#include  <queue>
#include  <cmath>
#include  <iomanip>
#include  <set>
#include  <map>
#include  <new>
#include <cstdint>
#include <cctype>
using namespace std;
#define rep(i,n)  for(int i = 0; i < n; i++)
#define lrep(i,n,m)  for(int i = n; i < m; i++)

using ll = long long;
using Vii = vector<vector<int> >;
using Gjudge = vector<vector<bool>>;
using Vi = vector<int>;
using Vl = vector<ll>;
using Vll = vector<vector<ll> >;
using Vs = vector<string>;
using Vb = vector<bool>;
using the = pair<int, int>;
using lthe = pair<ll, ll>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int Mod = static_cast<int>(1e9 + 7);
const int INF = INT_MAX;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };

int main()
{
    int n, p;
    cin >> n >> p;
    Vi A(n);
    rep(i, n)  cin >> A[i];

    Vll dp(n, Vl(2, 0));
    dp[0][0] = 1;
    if (A[0] % 2 == 0) {
        dp[0][0]++;
    }
    else {
        dp[0][1] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (A[i] % 2 == 0) {
            dp[i][0] = dp[i - 1][0] * 2;
            dp[i][1] = dp[i - 1][1] * 2;
        }
        else {
            dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
            dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
        }
    }
    cout << dp[n - 1][p] << endl;
}
