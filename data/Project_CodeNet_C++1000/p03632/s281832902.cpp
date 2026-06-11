#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
using namespace std;
using ll = long long;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int ans = -1;
    if (B < C || D < A) {cout << 0 << endl; return 0;}
    FOR(i, min(A, C), max(B, D) + 1) {
        if (A <= i && i <= B && C <= i && i <= D) ans += 1;
    }
    cout << ans << endl;
    return 0;
}