#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int N, L, T;
int X[100000], W[100000];
int ans[100000];

signed main() {
    cin >> N >> L >> T;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> W[i];
        W[i] = W[i] % 2 * 2 - 1;
        ans[i] = (X[i] + W[i] * T + L * (int)1e9) % L;
    }
    int org = 0;
    for (int i = 0; i < N; i++) {
        if (ans[0] > ans[i]) {
            org++;
        }
    }
    stable_sort(ans, ans + N);
    if (W[0] == 1 && org + 1 < N && ans[org] == ans[org + 1]) {
        org++;
    }
    int a1 = 0;   //1周で何回なり替わるか
    for (int i = 1; i < N; i++) {
        if (W[0] != W[i]) {
            a1 += 2;
        }
    }
    int a2 = 0;   //T%L秒で何回なり替わるか
    for (int i = 1; i < N; i++) {
        if (W[0] != W[i]) {
            if ((L - X[i] * W[i] - X[0] * W[0]) % L <= T % L * 2) {
                a2++;
            }
            if ((L - X[i] * W[i] - X[0] * W[0]) % L + L <= T % L * 2) {
                a2++;
            }
        }
    }
    int a = (T / L * a1 + a2) % N;
    int start = (N - W[0] * a) % N;
    for (int i = 0; i < N; i++) {
        cout << ans[(i + start + org) % N] << endl;
    }
    return 0;
}
