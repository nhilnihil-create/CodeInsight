#include <bits/stdc++.h>
using namespace std;
using Int = long long;
const Int MOD = 1000000007;
int main() {
    int N; cin >> N;
    vector<int> X(N); for (auto &x : X) cin >> x;
    Int ans = 1, cnt = 0, i = 0;
    for (int t = 0; t < N; t++) {
        while (i < N && X[i] >= cnt * 2 + 1) i++, cnt++;
        if (i < N && X[i] == cnt * 2) i++, cnt++;
        ans = ans * cnt % MOD;
        cnt--;
    }
    cout << ans << '\n';
    return 0;
}
