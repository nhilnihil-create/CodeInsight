#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, x;
    cin >> N >> x;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    vector<int> mi(N, INT_MAX);
    ll ans = LLONG_MAX;
    for (int i = 0; i < N; ++i) {
        ll tmp = (ll)i * x;
        for (int j = 0; j < N; ++j) {
            int l = (j < i ? j - i + N : j - i);
            mi[j] = min(a[l], mi[j]);
            tmp += mi[j];
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}
