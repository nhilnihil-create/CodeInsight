#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
vector<ll> a;

int main() {
    cin >> N;
    a.resize(3 * N);
    rep(i, 3 * N) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll ans = 0;
    // 第2グループから2つずつとる
    for (int i = N; i <= 3 * N - 1; i+= 2) {
        // cout << i << endl;
        ans += a[i];
    }

    cout << ans << endl;
}