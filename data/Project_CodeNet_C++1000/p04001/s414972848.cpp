#include<bits/stdc++.h>

using namespace std;

void solve() {
    string S; cin >> S;
    int N = S.length();
    long long ans = 0;
    for (int bit = 0; bit < (1<<(N-1)); bit++) {
        long long tmp = 0;
        for (int i = 0; i < N-1; i++) {
            tmp *= 10;
            tmp += S[i] - '0';
            if (bit & (1<<i)) {
                ans += tmp;
                tmp = 0;
            }
        }
        tmp *= 10;
        tmp += S.back() - '0';
        ans += tmp;
    }

    cout << ans << endl;
}


int main() {
    solve();
    return 0;
}