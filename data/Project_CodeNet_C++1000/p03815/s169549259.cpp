#include <iostream>
#include <vector>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
using ll = long long;
using namespace std;

int main() {
    ll x;
    cin >> x;

    ll d = x / 11LL;
    ll ans = 2 * d;
    int n = x % 11;

    if (n == 0);
    else if (n <= 6) ans++;
    else if (n <= 11) ans += 2;

    cout << ans << endl;

    return 0;
}