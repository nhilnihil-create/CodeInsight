#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;

bool dp[10200];

int main() {
    int N;
    cin >> N;

    int s[N];
    rep(i, N) cin >> s[i];

    rep(i, 10001) dp[i] = false;
    dp[0] = true;

    rep(i, N) {
        for (int j=10000; j>=0; j--) {
            if (dp[j]) dp[j+s[i]] = true;
        }
    }

    int ans = 0;
    rep(i, 10000) {
        if (i%10 != 0 && dp[i]) ans = max(ans, i);
    }

    cout << ans << endl;

    return 0;
}

