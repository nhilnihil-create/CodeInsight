#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
    int n;
    cin >> n;
    vector<ll> t(n);
    ll ans = 1;
    rep(i,n) {
        ll t;
        cin >> t;
        ans = lcm(ans, t);
    }
    cout << ans << endl;
    return 0;
}