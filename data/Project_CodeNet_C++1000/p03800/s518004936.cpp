#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> solve() {
    ll N;
    string S;
    cin >> N >> S;
    vector<bool> SS(N);
    for ( int i = 0; i < N; i++ ) {
        SS[i] = S[i] == 'x';
    }
    bool ok = false;
    int b[] = {0, 1};
    for ( int i1 = 0; i1 < 2; i1++ ) {
        for ( int i2 = 0; i2 < 2; i2++ ) {
            vector<int> v(N);
            v[0] = b[i1];
            v[1] = b[i2];
            for ( int i = 1; i < N-1; i++ ) {
                v[i+1] = v[i] ^ v[i-1] ^ SS[i];
            }
            if ( v[0] != v[N-1] ^ v[N-2] ^ SS[N-1] ) continue;
            if ( v[1] != v[0] ^ v[N-1] ^ SS[0] ) continue;
            return v;
        }
    }
    return vector<int>();
}

int main() {
    auto ans = solve();
    if ( ans.size() == 0 ) {
        cout << -1 << "\n";
    } else {
        for ( int i = 0; i < ans.size(); i++ ) {
            cout << (ans[i] == 0 ? 'S' : 'W' );
        }
        cout << "\n";
    }
    return 0;
}