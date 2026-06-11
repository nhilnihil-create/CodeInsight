#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int a, b, c, d, f, x = 0, y = 0;
    double e = 0, w = 0;
    cin >> a >> b >> c >> d >> e >> f;
    for (int i = 0; i <= 30; i++) for (int j = 0; j <= 30; j++) if (i * a * 100 + j * b * 100 <= f) {
        int g = i * a * 100 + j * b * 100;
        if (!i && !j) continue;
        for (int k = 0; k <= 3000; k++) for (int l = 0; l <= 3000; l++) if (g + k * c + l * d <= f) {
            int h = k * c + l * d;
            //cout << g << ' ' << h << '\n';
            if (100 * h <= e * g) {
                //cout << g << ' ' << h << '\n';
                if (1.0 * h / g > w) {
                    w = 1.0 * h / g;
                    x = g + h;
                    y = h;
                }
            }
        }
    }
    if (!x) x = a * 100;
    cout << x << ' ' << y << '\n';
}
