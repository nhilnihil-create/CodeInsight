#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i] >> b[i];
    ll ans = 0;
    ll cnt = 0;
    for(int i = n-1; i >= 0; i--){
        if((a[i] + cnt)%b[i] == 0) continue;
        ans += b[i] - (a[i] + cnt)%b[i];
        cnt += b[i] - (a[i] + cnt)%b[i];
    }
    cout << ans << endl;
    return 0;
}
