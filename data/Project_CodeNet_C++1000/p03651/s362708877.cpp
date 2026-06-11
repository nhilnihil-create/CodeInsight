#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

int main(){
    ll n,k; cin >> n >> k;
    bool flag1 = false,flag2 = false;
    vector<ll> a(n);

    rep(i,n){
        cin >> a[i];
        if(a[i] == k){
            flag1 = true;
            flag2 = true;
        }

        if(a[i] > k){
            flag1 = true;
        }
    }

    rep(i,n-1){
        ll tmp1 = abs(a[i]-a[i-1]);
        ll tmp2 = gcd(a[i],a[i+1]);
        if(k%gcd(tmp1,tmp2) == 0){
            flag2 = true;
        }

    }

    if(flag1 && flag2) cout << "POSSIBLE";
    else cout << "IMPOSSIBLE";

    return 0;
}