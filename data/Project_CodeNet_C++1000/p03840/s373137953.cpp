#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll a[7];
    for(int i = 0; i < 7; i++) cin >> a[i];
    ll ans = a[0] / 2 * 2 + a[1] + a[3] / 2 * 2 + a[4] / 2 * 2;
    if(a[0] % 2 + a[3] % 2 + a[4] % 2 == 2 && min(a[0], min(a[3], a[4])) > 0) ans++;
    if(a[0] % 2 + a[3] % 2 + a[4] % 2 == 3) ans += 3;
    cout << ans << endl;
}
