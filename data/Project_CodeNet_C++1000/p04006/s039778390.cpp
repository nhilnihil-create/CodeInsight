typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n,x;
    std::cin >> n>>x;
    vector<ll> a(n);
    vector<vector<ll>> b(n,vector<ll>(n+2,(ll)1e15));
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            b[i][j] = min(b[i][j-1], a[(i+j-1)%n]);
        }
    }
    ll ans = 0;
    
    for (int i = 0; i < n; i++) {
        ll res = 1e16;
        for (int k = 0; k <= n; k++) {
            res = b[i][n];
        }
        ans += res;
    }
    ans += x*n;
    
    for (int m = 0; m < n; m++) {
        ll res2 = 0;
        for (int i = 0; i < n; i++) {
            res2 += b[i][m+1];
        }
        res2 += x*m;
        ans = min(res2,ans);
    }
    
    std::cout << ans << std::endl;
}
