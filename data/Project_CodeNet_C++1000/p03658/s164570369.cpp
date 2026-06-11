#include <bits/stdc++.h>

using namespace std;

int N, K;

void solve() {
    cin >> N >> K;
    vector<int> L(N);

    for (int i = 0; i < N; ++i) cin >> L[i];
    sort(L.begin(), L.end(), greater<int>());

    int ans = 0;
    for (int i = 0; i < K; ++i) ans += L[i];
    cout << ans << endl;
}

int main() {
    solve();
}