#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using Graph = vector<vector<pii>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    string S[2];
    cin >> N >> S[0] >> S[1];

    int l = 0;
    ll ans = 0;
    if (S[0][0] == S[1][0]) {
        ans += 3;
        l++;
    } else {
        ans += 6;
        l += 2;
    }

    while (l < N) {
        if (S[0][l] == S[1][l]) {
            ans *= (S[0][l - 1] == S[1][l - 1] ? 2 : 1);
            ans %= MOD;
            l++;
        } else {
            ans *= (S[0][l - 1] == S[1][l - 1] ? 2 : 3);
            ans %= MOD;
            l += 2;
        }
    }

    cout << ans << endl;

    return 0;
}
