#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;

int main() {
    ll n; cin >> n;
    ll t, ans = 1LL;
    for(int i = 0;i < n;i++){
        cin >> t;
        ans = LCM(t,ans);
    }
    cout << ans;
}


