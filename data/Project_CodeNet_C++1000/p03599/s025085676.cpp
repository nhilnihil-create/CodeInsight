#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    int n = 1;
    int m = -1;
    for (int a = 0; 100 * A * a <= F; a++) {
        int x = F - 100 * A * a;
        for (int b = 0; 100 * B * b <= x; b++) {
            int y = min(x - 100 * B * b, E * (A * a + B * b));
            for (int c = 0; c * C <= y; c++) {
                int d = (y - (c * C)) / D;
                if (m * (a * A + b * B) < (c * C + d * D) * n) {
                    n = a * A + b * B;
                    m = c * C + d * D;
                }
            }
        }
    }
    cout << n * 100 + m << " " << m << endl;
}