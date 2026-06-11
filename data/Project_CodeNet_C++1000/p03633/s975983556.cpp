#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
const ld pi = 3.14159265358979323846;

//最小公倍数(LCM)
ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b; // Be careful not to overflow
}

int main() {
    ll n;
    cin>>n;
    vector<ll> t(n);
    rep(i,n) cin>>t[i];
    ll LCM=t[0];
    rep2(i,1,n) LCM=lcm(LCM,t[i]);
    cout<<LCM<<endl;
}