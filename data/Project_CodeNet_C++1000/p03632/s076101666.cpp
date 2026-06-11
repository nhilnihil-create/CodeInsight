#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int lower = max(A, C);
    int upper = min(B, D);
    int ans = max(upper - lower, 0);

    cout << ans << endl;

    return 0;
}
