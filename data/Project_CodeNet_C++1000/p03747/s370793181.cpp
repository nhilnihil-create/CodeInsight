#include <bits/stdc++.h>
using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int N, L, T;
int X[110000], W[110000];
int A[110000];

signed main() {
    cin >> N >> L >> T;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> W[i];
    }
    for (int i = 0; i < N; i++) {
        if (W[i] == 1) A[i] = (X[i] + T % L) % L;
        else A[i] = (X[i] + L - T % L) % L;
    }
    sort(A, A + N);
    int key = (X[0] + T % L) % L;
    if (W[0] == 2) key = (X[0] + L - T % L) % L;

    int idx1;
    if (W[0] == 1) {
        for (int i = 0; i < N; i++) {
            if (A[i] == key) {
                idx1 = i;
                break;
            }
        }
    } else {
        for (int i = N - 1; i >= 0; i--) {
            if (A[i] == key) {
                idx1 = i;
                break;
            }
        }
    }

    int R1 = 0, R2 = 0;
    for (int i = 1; i < N; i++) {
        if (W[0] == W[i]) continue;
        R1 += 2;
        int dist = X[i] - X[0];
        if (W[0] == 2) dist = L - dist;
        if (dist < T % L * 2) R2++;
        if (dist < T % L * 2 - L) R2++;
    }
    int sw = R1 * (T / L) + R2;
    sw %= N;
    int idx2 = sw;
    if (W[0] == 2)idx2 = (N - sw) % N;

    for (int i = 0; i < N; i++) {
        cout << A[(i + idx1 - idx2 + N) % N] << endl;
    }
}
