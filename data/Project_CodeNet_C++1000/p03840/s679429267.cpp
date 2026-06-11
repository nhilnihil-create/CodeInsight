#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll a[7];
    for(int i = 0; i < 7; i++) cin >> a[i];
    ll ans = (a[0] / 2) * 2 + a[1] + (a[3] / 2) * 2 + (a[4] / 2) * 2;
    if(a[0] % 2 == 1 && a[3] % 2 == 1 && a[4] % 2 == 1) ans += 3;
    else if(a[0] % 2 == 1 && a[3] % 2 == 1 && a[4] >= 2) ans++;
    else if(a[0] % 2 == 1 && a[4] % 2 == 1 && a[3] >= 2) ans++;
    else if(a[4] % 2 == 1 && a[3] % 2 == 1 && a[0] >= 2) ans++;
    cout << ans << endl;
}