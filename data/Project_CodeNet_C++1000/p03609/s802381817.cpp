#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF = 1LL << 60;

int main(void){
    ll x; cin >> x;
    ll t; cin >> t;
    ll ans = x-t;
    if (ans>=0) cout << ans << endl;
    else cout << "0" << endl;
    
    return 0;
}
