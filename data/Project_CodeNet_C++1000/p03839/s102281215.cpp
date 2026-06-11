#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define sz(x) ((int)(x).size())
using namespace std;
using ll = long long;
using pp = pair<int, int>;
const int INF = 1e9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<ll> ruiseki(N + 1);
    vector<ll> NaM_r(N + 1);
    for (int i = 0; i < N; i++) {
        ruiseki[i + 1] = ruiseki[i] + A[i];
        NaM_r[i + 1] = NaM_r[i] + max(A[i], 0);
    }

    ll ans = -INF;
    for (int i = 0; i + K <= N; i++) {
        ll tmp = NaM_r[N];
        tmp += max(ruiseki[i + K] - ruiseki[i], 0LL);
        tmp -= NaM_r[i + K] - NaM_r[i];
        ans = max(tmp, ans);
    }
    cout << ans << endl;
}