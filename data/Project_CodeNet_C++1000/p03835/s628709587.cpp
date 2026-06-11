#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int K, S;
    cin >> K >> S;

    long long ans = 0;
    for ( int x = 0; x <= K; x++ ) {
        for ( int y = 0; y <= K; y++ ) {
            int z = S - x - y;
            if ( z < 0 ) break;
            if ( K < z ) continue;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
