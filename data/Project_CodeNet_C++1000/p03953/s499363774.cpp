#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int N, M, K;
int x[100000], a[100000];
int diff[99999], perm[100][99999];
int ans[99999], finaly[99999];

signed main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < N - 1; i++) {
        diff[i] = x[i + 1] - x[i];
        perm[0][i] = i;
        ans[i] = i;
    }
    cin >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> a[i];
        swap(perm[0][a[i] - 2], perm[0][a[i] - 1]);
    }
    for (int i = 1; i < 100; i++) {
        for (int j = 0; j < N - 1; j++) {
            perm[i][j] = perm[i - 1][perm[i - 1][j]];
        }
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < 63; j++) {
            if (((K >> j) & 1) == 1) {
                ans[i] = perm[j][ans[i]];
            }
        }
    }
    int a = x[0];
    for (int i = 0; i < N - 1; i++) {
        cout << a << endl;
        a += diff[ans[i]];
    }
    cout << a << endl;
    return 0;
}
