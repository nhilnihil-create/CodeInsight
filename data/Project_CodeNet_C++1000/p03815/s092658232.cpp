#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n); ++i)
typedef long long ll;

const int mod = 1e9+7;

int main() {
    
    ll y = 6,x;
    cin >> x;
    ll ans;
    ll a = x/11;
    int b = x%11;
    if(b <=6 && b>=1) ans = a*2+1;
    else if(b >= 7) ans = a*2+2;
    else ans = a*2;
    cout << ans << endl;

}
