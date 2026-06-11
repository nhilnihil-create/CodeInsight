#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    string S;
    int K;
    cin >> S >> K;

    vector<int> c(S.size());
    rep(i, S.size()) c[i] = (S[i] - 'a');

    rep(i, S.size()) {
        if (S[i] == 'a')
            continue;
        if (K >= 26 - c[i]) {
            K -= 26 - c[i];
            c[i] = 0;
        }
    }

    if (K != 0) {
        c[S.size() - 1] += K;
        c[S.size() - 1] %= 26;
    }

    rep(i, S.size()) cout << char(c[i] + 'a');
    cout << endl;

    return 0;
}