#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    if(n%2==0){
        bool judge=true;
        for(ll i=0;i<n;i+=2){
            if(a[i]!=a[i+1]||a[i]!=i+1){
                judge=false;
                break;
            }
        }
        if(judge==false){
            cout << 0 << endl;
            return 0;
        }
    }
    else {
        bool judge=true;
        if(a[0]!=0) judge=false;
        for(ll i=1;i<n;i+=2){
            if(a[i]!=a[i+1]||a[i]!=i+1){
                judge=false;
                break;
            }
        }
        if(judge==false){
            cout << 0 << endl;
            return 0;
        }
    }
    ll x=n/2;
    ll ans = modpow(2,x,MOD);
    cout << ans << endl;
}
