#include<iostream>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    for (ll m = 0; m < N; m++) {
        if (C * (N - 1 - m) - D * m <= B - A && B - A <= -C * m + (N - 1 - m) * D) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}