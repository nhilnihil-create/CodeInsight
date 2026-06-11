#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1000100100;

int main() {
    ll N;
    cin >> N;

    vector<ll> T(N);
    ll sum = 0;
    REP(i, T.size()) {
        cin >> T[i];
        sum += T[i];
    }

    ll M;
    cin >> M;

    vector<ll> P(M), X(M);
    REP(i, M) {
        cin >> P[i] >> X[i];
    }

    REP(i, M) {
        ll dif = T[P[i] - 1] - X[i];
        cout << sum - dif << endl;
    }

    return 0;
}