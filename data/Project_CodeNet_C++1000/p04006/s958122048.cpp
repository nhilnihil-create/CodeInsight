#include <bits/stdc++.h>
using namespace std;

#define FOR(i, j, k) for (int i = j; i < k; i++)
#define REP(i, j) FOR(i, 0, j)
#define RFOR(i, k, j) for (int i = k - 1; i >= j; i--)
#define RREP(i, j) RFOR(i, j, 0)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

template <class T> bool chmax(T &a, const T &b) {
    if (a < b) {a = b; return 1;}
    return 0;
}

template <class T> bool chmin(T &a, const T &b) {
    if (b < a) {a = b; return 1;}
    return 0;
}

template <typename T> istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec) is >> x;
    return is;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
  
    ll n, x;
    cin >> n >> x;
  
    vll a(n);
    cin >> a;
  
    ll ans = (1LL << 50);
    vll b(n, (1LL << 50));
    REP(i, n) {
        REP(j, n) {
            b[j] = min(b[j], a[(j - i + n) % n]);
        }

        ll s = 0;
        REP(j, n) s += b[j];
        ans = min(ans, s + i * x);
    }

    cout << ans << endl;
    return 0;
}
