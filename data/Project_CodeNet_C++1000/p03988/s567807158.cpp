#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int N;
    cin >> N;
    int a, l = N+1, r = -1;
    vector<int> n(N+1);
    for ( int i = 0; i < N; i++ ) {
        cin >> a;
        n[a]++;
        l = min(l, a);
        r = max(r, a);
    }
    if ( (r+1)/2 != l ) return false;
    if ( r % 2 == 0 ) {
        if ( n[l] != 1 ) return false;
    } else {
        if ( n[l] != 2 ) return false;
    }
    for ( int i = l+1; i <= r; i++ ) {
        if ( n[i] < 2 ) return false;
    }
    return true;
}

int main() {
    string ans = solve() ? "Possible" : "Impossible";
    cout << ans << "\n";
    return 0;
}