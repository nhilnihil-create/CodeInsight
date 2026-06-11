#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    ll N, M, MOD = 1e9 + 7, ans = 1;
    cin >> N >> M;
    if (abs(N - M) > 1) ans = 0;
    for (int i = 1; i <= N; i++) ans = (ans * i) % MOD;
    for (int i = 1; i <= M; i++) ans = (ans * i) % MOD;
    if (N == M) ans = (ans * 2) % MOD;
    cout << ans << "\n";
}
