//#pragma 03
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define int long long
#define eb emplace_back
#define ef emplace_front
#define rep(i, x, n) for (int i = x; i < n; ++i)
#define mp make_pair
#define fi first
#define se second
#define ii pair<int, int>
#define endl '\n'
#define vi vector<int>
#define vii vector<pair<int, int>>
#define reverse(s) reverse(s.begin(), s.end())
#define ld long double
#define vs vector<string>
#define inf INT_MAX
#define vc vector<char>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define vb vector<bool>
#define lb(a, x) lower_bound(a.begin(), a.end(), x)
#define ub(a, x) upper_bound(a.begin(), a.end(), x) 
#define vvi vector<vi>
#define mine(a) min_element(a.begin(),a.end())
#define maxe(a) max_element(a.begin(), a.end())
#define iota(a,i) iota(a.begin(),a.end(),i)
#define fileopen(filename) if (fopen(filename".INP", "r")) {freopen(filename".INP", "r", stdin);freopen(filename".OUT", "w", stdout);}
int dp[5009][5009];
signed main() {
    fastio;
    int n;
    string s;
    cin >> n >> s;
    int l = s.length();
    //cout << l << 'a' << endl;
    dp[1][0] = 1;
    dp[0][0] = 1;
    rep(i, 1, n + 1) {
        rep(j, 0, n + 1) {
            if (!dp[i][j]) {
                if (j == 0 && i > 1)
                {
                    dp[i][j] = dp[i - 1][1] * 2 + dp[i - 1][0];
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1] * 2;
                }
                dp[i][j] %= 1000000007;

            }
        }
    }
    cout << dp[n][l];
}