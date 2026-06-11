#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    ll a, b, x;
    cin >> a >> b >> x;
    ll ans = 0;
    if(a == 0){
        ll val1 = b/x;
        ans = val1 + 1;
    }else{
        ll val1 = b/x;
        ll val2 = (a-1)/x;
        ans = val1 - val2;
    }
    cout << ans << endl;
    return 0;
}