#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,m;
    cin >> n >> m;
    if(abs(n-m)>1) {
        cout << 0 << endl;
        return 0;
    }

    ll p=1000000007;
    ll ans=1;
    for(int i = 1; i <= n; i++) {
        ans *= i;
        ans %= p;
    }
    for(int i = 1; i <= m; i++) {
        ans*=i;
        ans %=p;
    }
    if(n==m) {
        ans *= 2;
        ans %= p;
    }
    cout << ans << endl;

    return 0;
}