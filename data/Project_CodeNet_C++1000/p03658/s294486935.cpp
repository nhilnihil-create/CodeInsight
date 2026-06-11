#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N, K;
    cin >> N >> K;

    vec<int> l(N);
    rep(i, N) cin >> l[i];

    sort(all(l), greater<int>());
    int ans = 0;
    rep(i, K) ans += l[i];
    cout << ans << endl;
}
