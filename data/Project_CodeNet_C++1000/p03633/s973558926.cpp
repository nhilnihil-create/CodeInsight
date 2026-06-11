#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;

ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

ll lcm(ll a, ll b){
    return (a/gcd(a, b))*b;
}


int main() {

    int n; cin >> n;
    ll tmp;
    ll ans;

    rep(i,n){
        cin >> tmp;
        if(i == 0) ans = tmp;
        else ans = lcm(ans,tmp);
    }

    cout << ans;

    return 0;
}
