#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

signed main() {
    int n,k;
    cin >> n >> k;

    k--;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int ans = 1e18;
    for(int bit = 0; bit < (1 << (n - 1)); bit++){
        int cnt = 0;
        for(int i = 0; i < n - 1; i++){
            if(1 & (bit >> i)) cnt++;
        }
        if(cnt != k) continue;

        int tmp = 0;
        int maxv = a[0];
        for(int i = 1; i < n; i++){
            if(1 & (bit >> (n - 1 - i))){
                if(a[i] <= maxv){
                    tmp += (maxv + 1 - a[i]);
                    maxv = maxv + 1;
                }
            }
            maxv = max(maxv,a[i]);
        }
        ans = min(ans,tmp);
    }
    cout << ans << endl;
}
