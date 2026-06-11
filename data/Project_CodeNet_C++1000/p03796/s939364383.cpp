#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
const int MOD = 1e9+7;


int main(){
    ll n;
    cin >> n;
    ll ans=1;
    for(int i=1; i<=n; ++i){
        ans = (ans%MOD * i%MOD)%MOD;
    }
    cout << ans;
}
