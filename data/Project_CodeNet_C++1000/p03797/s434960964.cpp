#include <bits/stdc++.h>

using namespace std;

int main (void) {
    long long N, M;
    cin >> N >> M;

    long long ans;
    if ( N >= M / 2 ) {
        ans = M / 2;
    }
    else {
        ans = N + (M - 2 * N) / 4;
    }

    cout << ans << endl;

    return 0;
}

