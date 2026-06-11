#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M);
    rep(i, M) {
        cin >> a[i] >> b[i];
        --a[i], --b[i];
    }

    vector<int> cnt(N);
    rep(i, M)++ cnt[a[i]], ++cnt[b[i]];

    rep(i, N) cout << cnt[i] << endl;
}