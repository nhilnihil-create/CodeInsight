#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    ll diff = B - A;
    for (ll p = 0; p < N; ++p) {
        // p個を正に固定する
        ll mi = C * p - D * (N - p - 1);
        ll ma = D * p - C * (N - p - 1);
        if (mi <= diff && diff <= ma) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
