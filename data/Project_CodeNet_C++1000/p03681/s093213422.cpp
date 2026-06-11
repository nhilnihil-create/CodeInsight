#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
ll MOD = 1e9+7;

ll f(ll n){
    if(n==1 || n==1){
        return 1;
    }
    return (n * f(n-1)) % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    if(abs(n-m) > 1) cout << 0;
    else if(abs(n-m) == 1){
        ll ans = (f(n) * f(m)) % MOD;
        cout << ans;
    }
    else{
        ll ans =  ((f(n) * f(m) % MOD) * 2) % MOD;
        cout << ans;
    }
    return 0;
}
