#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ALL(a) (a).begin(), (a).end()
#define SORT(c) sort(ALL((c)))
#define debug(x)                 \
    do {                         \
        std::cout << #x << ": "; \
        view(x);                 \
    } while (0)

template <typename T>
void view(T e) {
    std::cout << e << std::endl;
}
template <typename T>
void view(const std::vector<T>& v) {
    for (const auto& e : v) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}
template <typename T>
void view(const std::vector<std::vector<T> >& vv) {
    for (const auto& v : vv) {
        view(v);
    }
}

int main() {
    ll N, C, K;
    cin >> N >> C >> K;
    vector<ll> T(N);
    rep(i, N) { cin >> T[i]; }
    sort(T.begin(), T.end(), greater<ll>());

    ll ans = 0;
    while (!T.empty()) {
        ll t = T.back();
        T.pop_back();
        rep(i, C - 1) {
            if (!T.empty()) {
                ll t_tmp = T.back();
                if (t_tmp <= t + K) {
                    T.pop_back();
                } else {
                    break;
                }
            }
        }
        ans++;
    }

    cout << ans << endl;

    return 0;
}
