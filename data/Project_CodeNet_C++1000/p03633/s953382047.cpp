#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll gcd(ll a, ll b) {
    if(b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

ll lcm2(ll a, ll b) {
    ll d = gcd(a, b);
    return a / d * b;
}

ll lcm(vector<ll> vec) {
    ll l = vec[0];
    REP(i, vec.size() - 1) {
        l = lcm2(l, vec[i + 1]);
    }
    return l;
}

int main() {
    ll N;
    cin >> N;

    vector<ll> T(N, 0);
    REP(i, N) {
        cin >> T[i];
    }

    cout << lcm(T) << endl;

    return 0;
}