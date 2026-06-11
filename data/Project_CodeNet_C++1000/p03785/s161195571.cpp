#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    int N, C, K;
    cin >> N >> C >> K;
    int T[N];
    rep(i, N) { cin >> T[i]; }
    sort(T, T + N);
    int ans = 1;
    int total = 1;
    int t = T[0];
    for (int i = 1; i < N; i++) {
        if (T[i] <= t + K && total < C) {
            total++;
        } else {
            ans++;
            total = 1;
            t = T[i];
        }
    }

    cout << ans << endl;
}