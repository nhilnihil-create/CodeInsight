#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

bool solve() {
    long long N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    rep(i, 0, N) {
        long long mx = i * D - (N - 1 - i) * C;
        long long mn = i * C - (N - 1 - i) * D;
        if(mn <= abs(A - B) && abs(A - B) <= mx) return true;
    }
    return false;
}

int main() {
    cout << (solve() ? "YES" : "NO") << '\n';
    return 0;
}
