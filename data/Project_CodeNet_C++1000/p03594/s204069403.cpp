#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int N = 2005;
char s[N][N], t[4] = {'R', 'Y', 'G', 'B'};
int n, m, d;

void paint(int sx, int sy, int z, char letter) {
    int k = sy, j = sx;
    for (int i = 2; i <= z; i += 2, k--, j++) {
        for (int h = 0; h < i; h++) {
            if (j >= 0 && j < n && k + h >= 0 && k + h < m) {
                s[j][k + h] = letter;
            }
        }
    }
    k += 2;
    for (int i = z - 2; i >= 2; i -= 2, k++, j++) {
        for (int h = 0; h < i; h++) {
            if (j >= 0 && j < n && k + h >= 0 && k + h < m) {
                s[j][k + h] = letter;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> d;

    if (d % 2) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                s[i][j] = t[(i + j) & 1];
            }
        }
    }
    else {
        for (int i = -N; i < N * 2; i += d) {
            for (int j = -N; j < N * 2; j += d) {
                paint(i, j, d, t[(i + N + j + N) / d & 1]);
            }
        }

        for (int i = -N; i < N * 2; i += d) {
            for (int j = -N; j < N * 2; j += d) {
                paint(i + d / 2, j + d / 2, d, t[((i + N + j + N) / d & 1) + 2]);
            }
        }

        int ct = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ct += (s[i][j] > 0);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << s[i] << "\n";
    }

    return 0;
}