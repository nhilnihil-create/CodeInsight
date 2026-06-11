#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int h, w;
    cin >> h >> w;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int idx = 0;
    int res[h][w];
    for (int i = 0; i < h; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < w; j++) {
                while (arr[idx] == 0)
                    idx++;
                res[i][j] = idx + 1;
                arr[idx]--;
            }
        }
        else {
            for (int j = w - 1; j >= 0; j--) {
                while (arr[idx] == 0)
                    idx++;
                res[i][j] = idx + 1;
                arr[idx]--;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
    return  0;
}