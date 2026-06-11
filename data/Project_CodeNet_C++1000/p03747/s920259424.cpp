#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

template <class T>
vector<T> Vec(size_t l, T v) { return vector<T>(l, v); }

template <class T, class... Ts>
auto Vec(size_t l, Ts... ts) {
    return vector<decltype(Vec<T>(ts...))>(l, Vec<T>(ts...));
}

template <typename T>
inline T iceil(T n, T d) { return (n + d - 1) / d; }

int main() {
    ll N, L, T;
    cin >> N >> L >> T;

    auto x = Vec<ll>(N, 0LL), w = Vec<ll>(N, 0LL);
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> w[i];
        w[i] = 3 - w[i] * 2;  // (1, 2) -> (1, -1)
    }

    ll confl = 0;  // 蟻0の衝突回数
                   // 最後に同じ場所についたときはカウントしない
    for (int i = 1; i < N; ++i) {
        if (w[0] == w[i]) continue;
        if (w[0] > 0) {
            confl += iceil(x[0] - x[i] + T * 2, L);
        } else {
            confl += iceil(x[i] - x[0] + T * 2, L) - 1;
        }
    }

    confl %= N, T %= L;
    ll id0 = (confl * w[0] + N) % N;  // 蟻0の最終的な番号

    for (int i = 0; i < N; ++i) {
        x[i] = (x[i] + T * w[i] + L) % L;
    }
    ll x0 = x[0];  // 蟻0の最終的な位置

    sort(x.begin(), x.end());
    auto itr = lower_bound(x.begin(), x.end(), x0);
    if (w[0] < 0) itr = --upper_bound(x.begin(), x.end(), x0);
    // 同じ位置に蟻が2匹いるとき、回る方向によってどっちを蟻0にするかが変わる

    auto ans = Vec<ll>(N, 0LL);
    for (int j = 0; j < N; ++j) {
        ans[(id0 + j) % N] = *itr;
        if (++itr == x.end()) itr = x.begin();
    }

    for (auto& e : ans) cout << e << endl;
    return 0;
}
