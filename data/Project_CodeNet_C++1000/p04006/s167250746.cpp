#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n, x;
    cin >> n >> x;
    ll a[100002];
    ll t[100002];
    for(int i = 0; i < n; i++) cin >> a[i];
    fill (t, t + n, 100000000000);
    ll ans = 100000000000000000;
    for(int count = 0; count < n; count++){
        ll sum = x * count;
        for(int i = 0; i < n; i++){
            t[i] = min(t[i], a[(i - count + n) % n]);
            sum += t[i];
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
}