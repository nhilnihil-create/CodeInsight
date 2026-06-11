#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,ext;
    cin >> n >> ext;
    vector<int> t(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }
    ll ans=ext;
    for(int i = 0; i < n-1; i++) {
        int tmp=min(ext,t[i+1]-t[i]);
        ans+=tmp;
    }
    cout << ans << "\n";
    return 0;
}