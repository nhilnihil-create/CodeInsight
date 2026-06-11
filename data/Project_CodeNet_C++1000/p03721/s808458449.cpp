#include <bits/stdc++.h>

using namespace std;

const int AMAX = 100000;

void solve() {
    long long N, K;
    cin >> N >> K;
    vector<long long> cnt(AMAX + 1);
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        cnt[a] += b;
    }

    for (int ans = 1; ans <= AMAX; ans++)
    {
        if (K <= cnt[ans])
        {
            cout << ans << endl;
            return;
        }
        K -= cnt[ans];
    }
}

int main() {
    solve();
    return 0;
}