#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, x;
    cin >> N >> x;
    vector<int> a(N);
    for (int i=0;i<N;i++) cin >> a[i];
    ll ans = 0;
    if (a[0] > x) {
        int p = a[0] - x;
        a[0] -= p;
        ans += p;
    }
    for (int i=1;i<N;i++){
        if (a[i-1]+a[i]>x) {
            int p = a[i-1]+a[i]-x;
            a[i] -= p;
            ans += p;
        }
    }
    cout << ans << "\n";
}