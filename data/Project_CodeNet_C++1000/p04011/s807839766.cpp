#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, K, X, Y;
    cin >> N >> K >> X >> Y;

    int total = 0;

    if (N >= K) {
        total = X * K + Y * (N - K);
    } else {
        total = X * N;
    }

    cout << total << endl;

    return 0;
}