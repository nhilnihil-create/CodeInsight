// 5/31
// 2-6-1. 線分状の格子点の個数
// 類題
#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    int Amax = -1;
    rep(i, N) {
        cin >> A[i];
        Amax = max(Amax, A[i]);
    }

    int g = A[0];
    for (int i = 1; i < N; i++) {
        g = gcd(g, A[i]);
    }

    if (K % g == 0 && K <= Amax) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}
