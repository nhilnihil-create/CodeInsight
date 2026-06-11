#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N;
int cnt[9];
 
signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    rep(i, N) {
        int a; cin >> a;
        a = min(3200ll, a);
        cnt[a/400]++;
    }
    int ans = 0;
    rep(i, 8) ans += cnt[i]>0;
    if (cnt[8]==0) cout << ans << " " << ans << endl;
    else {
        if (ans==0) cout << 1 << " " << cnt[8] << endl;
        else cout << ans << " " << ans+cnt[8] << endl;
    }
}