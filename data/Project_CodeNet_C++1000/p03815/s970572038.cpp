#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    ll x;
    cin >> x;
    ll ans = x/11;
    ans *= 2;
    if(x%11 <= 6 && x%11 > 0)ans += 1;
    if(6 < x%11) ans += 2;
    cout << ans << endl;
}