#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    ll a[100005];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll bw[100005];
    ll b[100005];
    bw[0] = b[0] = 0;
    for(int i = 1; i <= n; i++){
        bw[i] = bw[i - 1] + max(a[i - 1], 0ll);
        b[i] = b[i - 1] + a[i - 1];
    }
    ll ans = 0;
    for(int i = 0; i <= n - k; i++){
        ans = max(ans, bw[i] + max(b[i + k] - b[i], 0ll) + bw[n] - bw[i + k]);
    }
    cout << ans << endl;
}
