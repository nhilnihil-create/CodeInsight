#include <bits/stdc++.h>

using namespace std;

int W, H, N;
int x[100], y[100], a[100];

void solve() {
    int left = 0, right = W, top = H, bottom = 0;
    for (int i = 0; i < N; ++i) {
        if (a[i] == 1) left = max(left, x[i]);
        if (a[i] == 2) right = min(right, x[i]);
        if (a[i] == 3) bottom = max(bottom, y[i]);
        if (a[i] == 4) top = min(top, y[i]);
    }
    if (left >= right || top <= bottom) {
        printf("0\n");
    } else {
        printf("%d\n", (right - left) * (top - bottom));
    }
}

int main() {
    cin >> W >> H >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i] >> a[i];
    }
    solve();
    return 0;
}