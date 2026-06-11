#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

const int N = 1e5 + 10;
int n, C, K, t[N], mx = 0, cnt, ans;

int main() {
    cin >> n >> C >> K;
    rep(i, 1, n) scanf("%d", &t[i]);
    sort(t + 1, t + n + 1);
    rep(i, 1, n) {
        if (mx < t[i] || cnt == C) {
            // printf("%d .\n", i);
            ++ans;
            cnt = 1;
            mx = t[i] + K;
        } else {
            ++cnt;
        }
    }
    printf("%d\n", ans);
    return 0;
}
