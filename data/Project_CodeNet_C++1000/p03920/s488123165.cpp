/*
ID: y1197771
PROG: test
LANG: C++
*/
#include<bits/stdc++.h>
#define pb push_back
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
#define dbg(x) cout << #x << " at line " << __LINE__ << " is: " << x << endl
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;
const int maxn = 1e3 + 10;
int n;
int dp[1010];
void solve() {
    ll x;
    cin >> x;
    ll left = 1, right = x;
    while(left < right) {
        ll mid = (left + right + 1) / 2;
        if(mid * (mid + 1) / 2 <= x) {
            left = mid;
        } else right = mid - 1;
    }
    if(left * (left + 1) / 2 == x) {
        for (int i = 1; i <= left; i++) {
            cout << i << endl;
        }
        return;
    }
    ll t = left + 1 - (x - (left + 1) * left / 2);
    for (int i = 1; i <= left + 1; i++) {
        if(i == t) continue;
        cout << i << endl;
    }
}
int main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
