#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b, x;
    cin >> a >> b >> x;
    ll ans = b / x - (a + x - 1) / x + 1;
    cout << ans << endl;
}