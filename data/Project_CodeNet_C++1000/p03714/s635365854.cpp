#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define REP(i, n) FOR(i, 0, n)
#define REP1(i, n) FOR(i, 1, (n) + 1)
#define ALL(c) (c).begin(), (c).end()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(3 * n);
    REP(i, 3 * n) {
        cin >> a[i];
    }
    multiset<ll> f;
    multiset<ll> s;
    vector<ll> fsum(n + 1);
    ll sum = 0;
    REP(i, n) {
        sum += a[i];
        f.insert(a[i]);
    }
    fsum[0] = sum;
    REP1(i, n) {
        fsum[i] = fsum[i - 1] + a[n + i - 1];
        f.insert(a[n + i - 1]);
        auto itr = f.begin();
        fsum[i] -= *itr;
        f.erase(itr);
    }
    vector<ll> ssum(n + 1);
    sum = 0;
    for (int i = 3 * n - 1; i >= 2 * n; i--) {
        sum += a[i];
        s.insert(a[i]);
    }
    ssum[n] = sum;
    for (int i = 2 * n - 1; i >= n; i--) {
        ssum[i - n] = ssum[i + 1 - n] + a[i];
        s.insert(a[i]);
        auto itr = --s.end();
        ssum[i - n] -= *itr;
        s.erase(itr);
    }

    ll mx = -1001001001001001001;
    REP(i, n + 1) {
        chmax(mx, fsum[i] - ssum[i]);
    }

    cout << mx << endl;
}