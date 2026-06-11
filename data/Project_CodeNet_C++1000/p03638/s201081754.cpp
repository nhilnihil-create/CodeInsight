#include <iostream>
using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    int grid[110][110] = {0};

    int j = 0, k = 0;
    bool f = true;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        while (a) {
            grid[j][k] = i;
            if (f) {
                if (k == w - 1) {
                    j++;
                    f = false;
                }
                else k++;
            }
            else {
                if (k == 0) {
                    j++;
                    f = true;
                }
                else k--;
            }
            a--;
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}