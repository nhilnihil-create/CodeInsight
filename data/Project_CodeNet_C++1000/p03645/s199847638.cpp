#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int N, M, a, b;
    cin >> N >> M;
    vector<bool> from1(N, false), fromN(N, false);
    rep(i, M) {
        cin >> a >> b;
        if (a == 1) from1[b] = true;
        if (b == N) fromN[a] = true;
    }
    rep(i, N) {
        if (from1[i] && fromN[i]) {
            cout << "POSSIBLE\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
}