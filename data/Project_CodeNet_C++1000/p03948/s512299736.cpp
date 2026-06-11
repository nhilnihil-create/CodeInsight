#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;

map<ll, ll> mp;

int main(int argc, char const *argv[]) {
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    REP(i,n) cin >> a[i];
    ll m = a[0];
    ll diff = -LINF;
    for (int i = 1; i < n; ++i) {
        if (a[i] < m) m = a[i];
        else mp[a[i]-m]++;
    }
    cout << mp.rbegin()->second << endl;
    return 0;
}