#include <bits/stdc++.h>
using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int H, W, h, w;
int a[550][550];
signed main() {
    cin >> H >> W >> h >> w;
    bool tflag = false;
    if (W % w != 0) {
        tflag = true;
        swap(H, W);
        swap(h, w);
    } else if (H % h == 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    for (int i = 0; i <= H; i++)a[i][1] = -i;
    for (int i = 0; H - h * i > 0; i++)a[H - h * i][1] = i + 1;
    for (int i = H; i > 0; i--)a[i][1] -= a[i - 1][1];
    for (int i = 1; i <= H; i++) {
        for (int j = 2; j <= W; j++)a[i][j] = a[i][j - 1];
    }
    if (tflag)swap(H, W);
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (tflag) cout << a[j][i] << " ";
            else cout << a[i][j] << " ";
        }
        cout << endl;
    }
}