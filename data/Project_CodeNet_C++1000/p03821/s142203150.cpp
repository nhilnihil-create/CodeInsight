#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const int MAX = 100000;
static const int NIL = -1;
using namespace std;

ll gcd(ll a, ll b){
    if(a%b == 0){
        return b;
    }else{
        return gcd(b, a%b);
    }
}

ll lcm(ll a, ll b){
    return a*b / gcd(a, b);
}


int main() {

    ll n; cin >> n;
    ll sum = 0;
    ll ans = 0;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    for(int i = n-1; i >= 0; i --){
        a[i] += sum;
        if(a[i] != 0) {
            if(a[i] % b[i] != 0) {
                ans += (b[i] - a[i] % b[i]);
                sum += b[i] - a[i] % b[i];
            }
        }
    }

    cout << ans;

    return 0;
}
