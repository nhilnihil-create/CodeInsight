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

const int N = 205;
int h, w;
char ans[N][N];
int main() {
    cin >> h >> w;
    for (int i = 1; i <= h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> ans[i][j];
        }
    }
    for (int i = h * 2; i > 0; --i) {
        for (int j = 0; j < w; ++j) {
            ans[i][j] = ans[(i + 1) / 2][j];
        }
    }
    for (int i = 1; i <= h * 2; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
