#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solve() {
    string S;
    ll K;
    cin >> S >> K;
    for ( int i = 0; i < S.size(); i++ ) {
        ll d = (26 - (S[i] - 'a')) % 26;
        if ( d <= K ) {
            S[i] = 'a';
            K -= d;
        }
    }
    S[S.size()-1] = (char)('a' + (K + (S[S.size()-1] - 'a')) % 26);
    return S;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}