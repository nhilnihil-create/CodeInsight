#include <bits/stdc++.h>

using namespace std;

int main (void) {
    long long x;
    cin >> x;

    long long ans = ((x - 1) / 11 + 1) * 2;
    if ( x <= 11 * (ans / 2) - 5 )
        ans--;

    cout << ans << endl;
    return 0;
}
