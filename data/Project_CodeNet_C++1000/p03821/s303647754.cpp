#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
 
int main() {
    int n; 
    cin >> n;
    ll a[n+10], b[n+10];
    
    rep(i, n) cin >> a[i] >> b[i];
        
    ll ans = 0;
    for (int i = n-1; i >= 0; i--)
    {   //ll rem = a[i] % b[i];
        if ((a[i] + ans) % b[i] == 0) continue;
        ans += b[i];
        ans -= (a[i]+ans) % b[i];
    }
    cout << ans << endl;
    return 0;
}