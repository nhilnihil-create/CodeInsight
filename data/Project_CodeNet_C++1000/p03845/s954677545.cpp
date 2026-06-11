#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    ll N, M;
    cin >> N;
    vector<ll> T(N);
    rep(i,N) cin >> T.at(i);
    cin >> M;
    vector<ll> P(M), X(M);
    rep(i,M) cin >> P.at(i) >> X.at(i);
    ll total = 0;
    rep(i,N) total += T.at(i);
    rep(i,M) cout << total - (T.at(P.at(i)-1) - X.at(i)) << endl;
}

