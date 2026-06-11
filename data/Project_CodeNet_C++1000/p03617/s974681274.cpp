#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int q, h, S, D; cin >> q >> h >> S >> D;
    int n; cin >> n;
    int Q = 4 * q;
    int H = 2 * h;
    int L = min(min(Q, H), S);
    Int ans;
    if (2 * L > D) {
        ans = ((Int)n / 2) * D;
        ans += ((Int)n % 2) * L; 
    }
    else {
        ans = (Int)L * n;
    }
    cout << ans << endl;
}