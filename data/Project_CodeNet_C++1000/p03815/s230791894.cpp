#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x;
    cin >> x;
    ll ans=(x/11)*2;
    if(x%11>6)      ans+=2;
    else if(x%11>0) ans+=1;
    cout << ans << "\n";
    return 0;
}