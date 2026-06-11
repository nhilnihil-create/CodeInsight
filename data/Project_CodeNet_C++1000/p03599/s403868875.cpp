#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
#define debug(x) cerr << #x << ": " << x << '\n'
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using ull = unsigned long long;
const int INF = 1e9;
// const int MOD = 1e9 + 7;

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    vector<int> W, S;
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            int w = A * i + B * j;
            if (w != 0 && w * 100 <= F) W.push_back(w);
        }
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            int s = C * i + D * j;
            S.push_back(s);
        }
    }
    sort(S.begin(), S.end());
    int ans_a = 100 * A;
    int ans_b = 0;
    for (auto w : W) {
        auto it = upper_bound(ALL(S), min(w * E, F - w * 100));
        if (it != S.begin()) {
            int s = *(it - 1);
            if (ans_b * (100 * w + s) < s * (ans_a + ans_b)) {
                ans_a = 100 * w;
                ans_b = s;
            }
        }
    }
    cout << ans_a + ans_b << " " << ans_b << endl;
}
