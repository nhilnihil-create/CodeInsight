#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    vector<ll> minus(m+2, 0), plus(m+2, 0), sum(m+2, 0);
    int t = 0;
    for (int i = 1; i < n; i++) {
        if (a[i-1] < a[i]) {
            ans += a[i]-a[i-1];
            sum[a[i]+1] += a[i]-a[i-1]-1;
        }
        else {
            ans += a[i];
            sum[a[i]+1] += a[i]+m-a[i-1]-1;
            if (a[i] != 1)t++;
        }
        plus[a[i-1]+1]++;
        minus[a[i]]++;
    }
    ll now = ans;
    for (int i = 2; i <= m; i++) {
        now -= t;
        now += sum[i];
        ans = min(ans, now);
        t = t - minus[i] + plus[i];
        //cout << i << " " << now << endl;
    }
    cout << ans << endl;
    return 0;
}
