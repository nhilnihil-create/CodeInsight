#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>
#include <random>
#include <complex>
#include <functional>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll inf = 1LL << 60;

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;
    vec X(N);
    map<ll, ll> cnt;
    Rep (i, N) {
        cin >> X[i];
        cnt[X[i]]++;
    }

    map<ll, ll> p, m;
    for (auto e : cnt) {
        ll n = e.first, c = e.second;
        m[n%M] += c;
        p[n%M] += c/2;
    }

    // for (auto e : m) {
    //     cout << e.first << " " << e.second << "\n";
    // }

    ll ans = m[0]/2;
    if (M%2 == 0) ans += m[M/2]/2;
    for (ll i = 1; i < (M+1)/2; i++) {
        ll tmp = min(m[i], m[M-i]);
        ans += tmp;
        m[i] -= tmp;
        m[M-i] -= tmp;
        if (m[M-i] == 0) {
            ans += min(p[i], m[i]/2);
        } else {
            ans += min(p[M-i], m[M-i]/2);
        }
    }

    cout << ans << endl;


}