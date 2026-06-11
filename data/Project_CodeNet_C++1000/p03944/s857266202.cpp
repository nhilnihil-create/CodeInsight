#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;
int w, h, n, x, y, a;

int main() {
    cin >> w >> h >> n;
    int x_min = 0, x_max = w, y_min = 0, y_max = h;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> a;
        if (a == 1) {
            x_min = max(x_min, x);
        } else if (a == 2) {
            x_max = min(x_max, x);
        } else if (a == 3) {
            y_min = max(y_min, y);
        } else {
            y_max = min(y_max, y);
        }
    }
    cout << max(0, x_max - x_min) * max(0, y_max - y_min) << endl;
    return 0;
}
