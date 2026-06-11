#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    unsigned ll ans;
    rep(i, n){
        ll x; cin >> x;
        if(i==0) ans = x;
        else{
            ans = ans/gcd(x, ans) *x;
        }
    }
    cout << ans;
    return 0;
}
