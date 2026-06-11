#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    ll r = a%b;
    ll re;
    if(r == 0) re = b;
    else re = gcd(b, r);
    return re;
}

int main(){
    int n;
    cin >> n;
    vector<ll> t(n);
    for(int i = 0; i < n; i++) cin >> t[i];
    ll ans = 1;
    for(int i = 0; i < n; i++){
        ans = ans * (t[i] / gcd(ans, t[i]));
    }
    cout << ans << endl;
}