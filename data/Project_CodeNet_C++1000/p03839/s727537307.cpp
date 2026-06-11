// https://atcoder.jp/contests/agc008/tasks/agc008_b
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

#define EPS (1e-9)
#define INF (1e9)
#define INFL (1e18)
#define MOD (1000000007)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = (n)-1; i >= 0; i--)
#define FOREACH(x, a) for (auto &(x) : (a))
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define LEN(x) (sizeof(x) / sizeof(*(x)))
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
// ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1, 0);
    REP(i, n) cin >> v[i];
    ll sum = 0, now = 0, nowm = 0;
    REP(i, n) sum += max(0, v[i]);
    // 区間Kに含まれる0未満の合計が最小の区間を探す
    REP(i, k) {
        now += v[i];
        nowm += max(0, v[i]);
    }
    ll maxv = -INFL;
    REP(i, n - k + 1) {
        maxv = max(maxv, sum - nowm + max(0LL, now));
        now += v[i + k] - v[i];
        nowm += max(0, v[i + k]) - max(0, v[i]);
    }
    cout << maxv << endl;

    return 0;
}