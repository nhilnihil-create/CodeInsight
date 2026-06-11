#include<bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll x; cin >> x;

    ll ans = 0;
    ans = x / 11 * 2;
    if(x % 11 > 6) ans += 2;
    else if(x % 11 > 0) ans += 1;
    put(ans);
    
}