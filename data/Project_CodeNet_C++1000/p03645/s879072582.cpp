#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<int> a(m),b(m);
    vector<bool> f(n+1),s(n+1);
    for(int i=0; i<m; i++) {
        cin >> a[i] >> b[i];
        if(a[i] == 1) f[b[i]] = true;
        if(b[i] == n) s[a[i]] = true;
    }
    bool ok = false;
    for(int i=1; i<=n; i++) {
        if(f[i] && s[i]) ok = true;
    }
    cout << (ok ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}