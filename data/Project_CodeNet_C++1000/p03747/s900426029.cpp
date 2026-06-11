#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int N, L, T; cin >> N >> L >> T;
    int x[N], w[N]; for (int i = 0; i < N; i++) cin >> x[i] >> w[i];
    int y[N];
    for (int i = 0; i < N; i++)
        y[i] = ((x[i] + T * (w[i] == 1 ? 1 : -1)) % L + L) % L;
    int y0 = y[0];
    sort(y, y+N);
    long long m = 0;
    for (int i = 1; i < N; i++)
        if (w[0] == 1 && w[i] == 2)
            m += (L + x[0] - x[i] + 2LL * T - 1) / L;
        else if (w[0] == 2 && w[i] == 1)
            m += (x[i] - x[0] + 2LL * T) / L;
    int j = w[0] == 1 ? m % N : ((- m) % N + N) % N;
    int p = lower_bound(y, y+N, y0) - y;
    int ans[N];
    for (int i = 0; i < N; i++)
        ans[(j + i) % N] = y[(p + i) % N];
    for (int x : ans) cout << x << endl;
}
