#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<int> l(N), r(N);
    rep(i, N) {
        cin >> l.at(i);
        cin >> r.at(i);
    }

    int ans = 0;
    rep(i, N) {
        ans += r.at(i) - l.at(i) + 1;
    }

    cout << ans << endl;

    return 0;
}