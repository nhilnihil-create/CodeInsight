#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    ll n;
    cin >> n;
    ll a[200500];
    ll sum[200050];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    ll ans = 1e17;
    for(int i = 1; i < n; i++) {
        ans = min(ans, abs(sum[i] - (sum[n] - sum[i])));
    }
    cout << ans << endl;
    return 0;
}
