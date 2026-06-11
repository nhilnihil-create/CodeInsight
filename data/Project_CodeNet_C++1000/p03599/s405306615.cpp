#include <bits/stdc++.h>

using namespace std;

int A, B, C, D, E, F;

void solve() {
    double mx = -1;
    int max_ws = 0, max_su = 0;
    for (int a = 0; 100 * a * A <= F; ++a) {
        for (int b = 0; 100 * b * B <= F; ++b) {
            int s = (A * a + B * b) * E;
            for (int c = 0; C * c <= s; ++c) {
                for (int d = 0; D * d <= s; ++d) {
                    int su = C * c + D * d;
                    int ws = 100 * A * a + 100 * B * b + su;
                    if (su > s) continue;
                    if (ws > F) continue;
                    if (mx < 100 * su / (double) ws) {
                        mx = 100 * su / (double) ws;
                        max_ws = ws;
                        max_su = su;
                    }
                }
            }
        }
    }
    printf("%d %d\n", max_ws, max_su);
}

int main() {
    cin >> A >> B >> C >> D >> E >> F;
    solve();
    return 0;
}