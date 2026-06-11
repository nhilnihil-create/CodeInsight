#include <bits/stdc++.h>
using namespace std;

int k, s, ans;

int main() {
    cin >> k >> s;
    for ( int i = 0; i <= k; i++ ) {
        for ( int j = 0; j <= k; j++ ) {
            if ( s - i - j >= 0 && s - i - j <= k ) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}