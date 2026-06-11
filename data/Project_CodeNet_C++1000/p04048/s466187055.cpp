#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(c) (c).begin(), (c).end()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
const int MOD = 1000000007;

long long gcd(long long m, long long n) {
    return n != 0 ? gcd(n, m % n) : m;
}

int main() {
    ll n, x;
    cin >> n >> x;
    ll y = n - x;
    ll t = n;
    ll q, r;
    while (x > 0 && y > 0) {
        if (x > y) {
            q = x / y;
            r = x % y;
        } else {
            q = y / x;
            r = y % x;
        }
        t += min(x, y) * 2 * q;
        if (r == 0) {
            t -= min(x, y);
        }
        if (x > y) {
            x = y;
            y = r;
        } else {
            y = x;
            x = r;
        }
    }
    cout << t << endl;
}
