#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

int n;
int a[210000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long tot = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot += a[i];
    }

    long long ans = 1000000000000000000LL;
    long long curt = 0;
    for (int i = 0; i < n-1; i++) {
        curt += a[i];
        ans = min(ans, abs( tot-2*curt ));
    }

    cout << ans << endl;
    return 0;
}