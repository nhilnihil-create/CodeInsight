#include <bits/stdc++.h>
#define rep(i,l,r)for(int i=(l);i<(r);i++)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    ll n;
    cin >> n;
    vector<ll> v(3*n);
    rep(i,0,3*  n)cin >> v[i];
    sort(v.begin(),v.end(),greater<ll>());
    ll ans = 0;
    for(ll i = 1,j = 0;j < n;i += 2,j++)ans += v[i];
    cout << ans << endl;

    return 0;
}