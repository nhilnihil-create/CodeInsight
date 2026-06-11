#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

void solve() {
    int N,K; cin >> N >> K;
    ll _gcd = -1;
    ll mx = 0;
    REP(_,N) {
        ll A;
        cin >> A;
        chmax(mx,A);
        if(_gcd < 0) _gcd = A;
        else _gcd = gcd(_gcd,A);
    }
    while ( mx > 0 ) {
        if(mx == K) {
            cout << "POSSIBLE" << endl;
            return;
        }
        mx -= _gcd;
    }
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    solve();
    return 0;
}