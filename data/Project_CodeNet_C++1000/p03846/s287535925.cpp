#include <bits/stdc++.h>

using namespace std;

#define MOD (1000000007)

int main (void) {
    int N;
    cin >> N;

    vector<int> a_map(N, 0);
    for ( int i = 0; i < N; i++ ) {
        int a;
        cin >> a;
        a_map.at(a)++;
    }

    bool can = true;
    for ( int i = 0; i < N; i++ ) {
        if ( N % 2 != 0 && i % 2 == 0 ) {
            if ( i == 0 ) {
                if ( a_map.at(i) != 1 ) {
                    can = false;
                    break;
                }
            }
            else {
                if ( a_map.at(i) != 2 ) {
                    can = false;
                    break;
                }
            }
        }
        if ( N % 2 == 0 && i % 2 != 0 ) {
            if ( a_map.at(i) != 2 ) {
                can = false;
                break;
            }
        }
    }

    if ( !can ) {
        cout << 0 << endl;
        return 0;
    }

    long long ans = 1;
    for ( int i = N-1; i > 0; i -= 2 ) {
        ans *= 2;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}
