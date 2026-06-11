#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define endl '\n'

signed main() {
    int n;
    cin >> n;

    vector<int> t(n), a(n);
    rep(i,n) cin >> t[i] >> a[i];

    int l = t[0], r = a[0];
    for(int i = 1; i < n; i++){
        int d = 1;
        bool flag = false;
        if(t[i] < l) {
            flag = true;
            d = (l + t[i] - 1) / t[i];
        }
        if(a[i] < r){
            flag = true;
            d = max(d, (r + a[i] - 1) / a[i]);
        }
        if(flag) {
            t[i] *= d;
            a[i] *= d;
        }
        l = t[i];
        r = a[i];
    }
    cout << t[n-1] + a[n-1] << endl;
}