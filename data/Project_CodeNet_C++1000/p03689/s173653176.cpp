#include <bits/stdc++.h>


using namespace std;


const int MAXN = 500 + 23;











int h, w, a, b, z[MAXN][MAXN];


int main() {
    cin >> h >> w >> a >> b;
    if (h % a) {
        cout << "Yes\n";
        for (int i = 1; i <= h; i++)
            for (int j = 0; j < w; j++)
                z[i - 1][j] = ((i % a)? h / a + 1: -a * (h / a + 1) + h / a);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++)
                cout << z[i][j] << ' ';
            cout << endl;
        }
        return 0;
    }
    if (w % b) {
        cout << "Yes\n";
        for (int i = 0; i < h; i++)
            for (int j = 1; j <= w; j++)
                z[i][j - 1] = ((j % b)? w / b + 1: -b * (w / b + 1) + w / b);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++)
                cout << z[i][j] << ' ';
            cout << endl;
        }
        return 0;
    }
    cout << "No";
    return 0;
}