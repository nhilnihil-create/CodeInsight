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

    ll N;
    cin >> N;
    vec a(N), b(N), ans(N, 0);
    ll s = 0;
    Rep (i, N) {
        cin >> a[i];
        s += a[i];
    }
    iota(b.begin(), b.end(), 0);
    sort(b.begin(), b.end(), [&](ll x, ll y){return a[x] > a[y];});

    ll tmp = b[0];
    Rep (i, N-1) {
        if (a[b[i]] == a[b[i+1]]) {
            chmin(tmp, b[i+1]);
        } else {
            ans[tmp] += (a[b[i]] - a[b[i+1]]) * (i+1);
            s -= (a[b[i]] - a[b[i+1]]) * (i+1);
            chmin(tmp, b[i+1]);
        }
    }
    
    ans[tmp] += s;

    Rep (i, N) {
        cout << ans[i] << "\n";
    }
}