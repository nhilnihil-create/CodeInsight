#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
    ll n,x, ans = 0; cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    for(int i = 0; i < n-1; i ++){
        if(a[i+1]+a[i] > x){
            if(a[i+1]+a[i]-x <= a[i+1]){
                ans += (a[i+1]+a[i]-x);
                a[i+1] -= (a[i+1]+a[i]-x);
            }else{
                ans += (a[i+1]+a[i]-x);
                a[i+1] = 0;
            }
        }
    }

    cout << ans;

}
