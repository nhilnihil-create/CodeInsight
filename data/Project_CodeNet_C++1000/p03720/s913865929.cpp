#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1000100100;

using Graph = vector<vector<ll>>;

int main() {
    ll N, M;
    cin >> N >> M;

    Graph G(N + 1);
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        G.at(a).emplace_back(b);
        G.at(b).emplace_back(a);
    }

    FOR(i, 1, N + 1) {
        ll ans = G.at(i).size();
        cout << ans << endl;
    }

    return 0;
}