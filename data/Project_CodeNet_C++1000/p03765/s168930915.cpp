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

    string S, T;
    cin >> S >> T;
    ll n_s = S.size(), n_t = T.size();
    vec s_s(n_s+1, 0), s_t(n_t+1, 0);

    Rep (i, n_s) {
        if (S[i] == 'A') {
            s_s[i+1] = s_s[i] + 1;
        } else {
            s_s[i+1] = s_s[i] + 2;
        }
    }

    Rep (i, n_t) {
        if (T[i] == 'A') {
            s_t[i+1] = s_t[i] + 1;
        } else {
            s_t[i+1] = s_t[i] + 2;
        }
    }

    ll q;
    cin >> q;

    while (q--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; c--;
        if (abs(s_s[b]-s_s[a]-s_t[d]+s_t[c]) % 3 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

}