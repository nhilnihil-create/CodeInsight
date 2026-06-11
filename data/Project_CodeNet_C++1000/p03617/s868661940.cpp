#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
using ll = long long;

int main() {
    vector<ll> l(4);
    rep(i, 0, 4) cin >> l[i];
    ll cost1 = min({4*l[0], 2*l[1], l[2]});
    ll n;
    cin >> n;
    ll ans = min((n/2)*l[3]+(n%2)*cost1, n*cost1);
    cout << ans << endl;
}