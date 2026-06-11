#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
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
const int INF = 2100100100;
const int MOD = 1e9 + 7;

ll N, M, K, Q, L;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> L;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }

    int last = -1;
    for (int i = 0; i < N - 1; i++) {
        if (a[i] + a[i + 1] >= L) {
            last = i;
        }
    }
    if (last == -1) {
        cout << "Impossible"
             << "\n";
        return 0;
    }
    vector<int> ans;

    for (int i = 0; i < last; i++) {
        ans.push_back(i);
    }
    for (int i = N - 2; i > last; i--) {
        ans.push_back(i);
    }
    ans.push_back(last);

    cout << "Possible"
         << "\n";
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] + 1 << "\n";
    }

    return 0;
}
