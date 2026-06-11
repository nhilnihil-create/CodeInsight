#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

#define rep(i, n) for(ll (i) = 0;(i) < (ll)(n);(i)++)
#define per(i, n) for(ll (i) = (ll)(n) - 1;(i) >= 0LL;(i)--)
#define iter(i, it) for(auto &(i): (it))

template<typename T, typename U> ostream& operator<<(ostream &s, const pair<T, U> m) {
    cout << "(" << m.first << ", " << m.second << ")";
    return s;
}
template<typename T, typename U> ostream& operator<<(ostream &s, const map<T, U> m) {
    ll c = 0;
    cout << "{ ";
    iter(i, m) cout << i << (c++ == m.size() - 1 ? " " : ", ");
    cout << "}";
    return s;
}
template<typename T> ostream& operator<<(ostream &s, const vector<T> &v) {
    cout << "{ ";
    rep(i, v.size()) cout << v[i] << (i == v.size() - 1 ? " " : ", ");
    cout << "}";
    return s;
}

int main(void) {
    ll N, P;
    ll oe[2] = {};
    cin >> N >> P;
    rep(i, N) {
        ll temp;
        cin >> temp;
        oe[temp % 2]++;
    }
    if(oe[1] == 0) {
        if(P) cout << 0 << endl;
        else cout << (1LL << N) << endl;
    } else {
        cout << (1LL << (N - 1)) << endl;
    }
    return 0;
}
