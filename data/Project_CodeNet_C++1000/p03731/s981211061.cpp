#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    ll N, T; cin >> N >> T;
    ll X = 0;
    ll pt = -1;
    rep(i, N) {
        ll t; cin >> t;
        X += T;
        if(pt >= 0&&t-pt<T) X -= (pt+T-t);
        pt = t;
    }
    cout << X;
}
