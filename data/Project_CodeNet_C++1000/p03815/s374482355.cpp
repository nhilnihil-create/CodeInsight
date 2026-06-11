#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
int main()
{
    ll x;
    cin >> x;
    ll ans;
    if(x<=6) ans = 1;
    else if(x<=11) ans = 2;
    else{
        ans = (x/11)*2;
        x%11 <= 6 ? ans++ : ans+=2;
        if(x%11 == 0) ans--;
    }
    cout << ans << endl;
    return 0;
}