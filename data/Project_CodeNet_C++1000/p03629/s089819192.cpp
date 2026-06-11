#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

vector<vector<int>> precalc(string &S) {
    int N = S.length();
    vector<vector<int>> res(N + 1, vector<int>(26, N));
    for (int i = N - 1; i >= 0; --i) {
        res[i] = res[i + 1];
        res[i][S[i] - 'a'] = i;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string A;
    cin >> A;

    auto nxt = precalc(A);
    int N = A.length();
    vector<int> dp(N + 1, 1e9);
    vector<char> mem(N + 1);
    dp[N] = 1;
    for (int i = N - 1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) {
            int tmp = (nxt[i][j] < N ? dp[nxt[i][j] + 1] : 0) + 1;
            if (dp[i] > tmp) {
                dp[i] = tmp;
                mem[i] = j + 'a';
            }
        }
    }

    int idx = 0;
    while (idx < N) {
        cout << mem[idx];
        idx = nxt[idx][mem[idx] - 'a'] + 1;
    }
    cout << endl;
    return 0;
}
