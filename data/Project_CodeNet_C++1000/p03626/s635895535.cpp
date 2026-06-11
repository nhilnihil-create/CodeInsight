#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

int main (void) {
    int N;
    string S1, S2;
    cin >> N >> S1 >> S2;

    long long ans;
    int idx = 0;
    bool is_prev_ver;

    if ( S1.at(0) == S2.at(0) ) {
        ans = 3;
        is_prev_ver = true;
        idx++;
    }
    else {
        ans = 6;
        is_prev_ver = false;
        idx += 2;
    }

    while ( idx < N ) {
        if ( S1.at(idx) == S2.at(idx) ) {
            if ( is_prev_ver ) ans *= 2;
            is_prev_ver = true;
            idx++;
        }
        else {
            if ( is_prev_ver ) ans *= 2;
            else ans *= 3;
            is_prev_ver = false;
            idx += 2;
        }
        if ( ans >= MOD ) ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}
