#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 998244353;

int main() {
    int n;
    cin >> n;
    vector<ll> as(n);
    rep(i, n) cin >> as[i];
    sort(all(as));
    ll tot = 0;
    int lc = 0;
    rep(i, n-1) {
        tot += as[i];
        if (2*tot < as[i+1]) lc = i+1;
    }
    int ret = n - lc;
    cout << ret << endl;
    return 0;
}