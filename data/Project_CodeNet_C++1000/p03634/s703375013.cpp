#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define MOD 1000000007LL

#define rep(i, n) for(ll (i) = 0LL;(i) < (ll)(n);(i)++)
#define rep2(i, s, e) for(ll (i) = (ll)(s);(i) < (ll)(e);(i)++)
#define repi(i, n) for(ll (i) = 0LL;(i) <= (ll)(n);(i)++)
#define repi2(i, s, e) for(ll (i) = (ll)(s);(i) <= (ll)(e);(i)++)
#define per(i, n) for(ll (i) = (ll)(n) - 1LL;(i) >= 0LL;(i)--)
#define per2(i, s, e) for(ll (i) = (ll)(s) - 1LL;(i) >= (ll)(e);(i)--)
#define peri(i, n) for(ll (i) = (ll)(n);(i) >= 0LL;(i)--)
#define peri2(i, s, e) for(ll (i) = (ll)(s);(i) >= (ll)(e);(i)--)
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
template<typename T> ostream& operator<<(ostream &s, const list<T> &v) {
    ll c = 0;
    cout << "{ ";
    iter(i, v) cout << i << (c++ == v.size() - 1 ? " " : ", ");
    cout << "}";
    return s;
}

int main(void) {
    ll N;
    ll Q, K;
    vector<vector<pair<ll, ll>>> V;
    stack<ll> st;
    vector<ll> distance;
    cin >> N;
    V.resize(N);
    distance.resize(N, -1);
    rep(i, N - 1) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        V[a].push_back({b, c});
        V[b].push_back({a, c});
    }
    cin >> Q >> K;
    distance[K - 1] = 0;
    st.push(K - 1);
    while(!st.empty()) {
        ll current = st.top();
        st.pop();
        iter(i, V[current]) {
            if(distance[i.first] == -1) {
                distance[i.first] = i.second + distance[current];
                st.push(i.first);
            }
        }
    }
    rep(i, Q) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        cout << distance[x] + distance[y] << endl;
    }
    return 0;
}
