#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<int>> grid(h, vector<int>(w, 0));
    bool forw = true;
    int i = 0, j = 0;
    for (int c = 1; c <= n; c++) {
        int a;
        cin >> a;
        while (a--) {
            grid[i][j] = c;
            if (forw)
                j++;
            else
                j--;
            if (j == w || j == -1) {
                forw = !forw;
                i++;
                j = (j == w ? w - 1 : 0);
            }
        }
    }
    for (auto v : grid) {
        for (int x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
}