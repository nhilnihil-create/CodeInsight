#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll gcd(ll a, ll b){
    if (a%b == 0) return(b);
    else return(gcd(b, a%b));
}
 
ll lcm(ll a, ll b){
    ll ans=a;
    ans /= gcd(a,b);
    ans *= b;
    return ans;
}

int main() {
    int n;
    cin >> n;
    ll ans = 1;
    for(int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        ans = lcm(ans, t);
    }
    cout << ans << endl;

    return 0;
}