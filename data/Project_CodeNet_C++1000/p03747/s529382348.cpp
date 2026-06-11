#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int N, L, T;

    cin >> N >> L >> T;
    int X[N], W[N];
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> W[i];
    }

    int count = 0;

    for (int i = 1; i < N; i++) {
        if (W[i] - W[0] > 0) {
            int dist = 2 * T - X[i] + X[0];
            if (dist >= 0) {
                count += dist / L + 1;
            }
        } else if (W[i] - W[0] < 0) {
            int dist = 2 * T + X[i] - X[0] - L;
            if (dist >= 0) {
                count -= dist / L + 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (W[i] == 1)
            X[i] = (X[i] + T) % L;
        else
            X[i] = (X[i] - T % L + L) % L;
    }

    int X0 = X[0];

    sort(X, X + N);

    int offset;

    for (int i = 0; i < N; i++) {
        if (X[i] == X0) {
            offset = i - count % N + N;
            if (W[0] == 2) break;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << X[(i + offset) % N] << endl;
    }

    return 0;
}
