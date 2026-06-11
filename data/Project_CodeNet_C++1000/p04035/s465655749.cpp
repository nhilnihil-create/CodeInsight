#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

int main() {
    int N, L;
    cin >> N >> L;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    vector<int> b(N - 1);
    rep(i, N - 1) b[i] = a[i + 1] + a[i];

    int last_i = -1;
    rep(i, N - 1) {
        if (b[i] >= L) {
            last_i = i;
            break;
        }
    }

    if (last_i == -1) {
        cout << "Impossible" << endl;
        return 0;
    }

    cout << "Possible" << endl;
    rep(i, last_i) cout << i + 1 << endl;
    for (int i = N - 2; i > last_i; i--) if (last_i < i) cout << i + 1 << endl;
    cout << last_i + 1 << endl;
}
