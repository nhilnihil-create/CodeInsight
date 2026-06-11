#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

long long LCM(long long a, long long b) {
    long long g = GCD(a, b);
    return a / g * b;
}

int main(){
    int n; cin >> n;
    vector<ll> t(n);
    rep(i,n) cin >> t[i];
    ll ans = 1;
    rep(i,n){
        ans = LCM(ans, t[i]);
    }
    cout << ans << endl;

}