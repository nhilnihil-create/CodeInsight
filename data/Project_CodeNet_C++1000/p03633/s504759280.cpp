#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(ll a, ll b) {
return b ? gcd(b, a%b) : a;
}
ll lcm(ll a, ll b){
return a / gcd(a, b) * b;
}


int main(){
    int n;
    cin >> n;
    vector<ll> t(n);
    rep(i,n) cin >> t[i];
    ll ans = t[0];
    for(int i=1; i<n; i++){
        ans = lcm(ans,t[i]);
    }
    cout << ans << endl;
    return 0;
}