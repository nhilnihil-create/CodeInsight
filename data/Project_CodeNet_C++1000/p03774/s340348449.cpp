#include <bits/stdc++.h>
using namespace std;

int a[60], b[60], c[60], d[60];

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> a[i] >> b[i];
    for (int i = 0; i < M; i++) cin >> c[i] >> d[i];

    for (int i = 0; i < N; i++) {
        int minDist = 1001001001, ans = 0;
        for (int j = 0; j < M; j++) {
            int dist = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if (minDist > dist) {
                minDist = dist;
                ans = j + 1;
            }
        }
        cout << ans << endl;
    }
}