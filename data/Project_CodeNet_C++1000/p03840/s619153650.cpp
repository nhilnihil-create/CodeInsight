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

int N, M, K, Q, W, H, R, C;
string S;

int main() {
    ll ai, ao, at, aj, al, as, az;
    cin >> ai >> ao >> at >> aj >> al >> as >> az;

    ll K = 0;
    K += ai / 2 * 2;
    K += aj / 2 * 2;
    K += al / 2 * 2;
    if (ai > 0 && aj > 0 && al > 0) {
        if ((ai % 2) + (aj % 2) + (al % 2) == 3) {
            K += 3;
        } else if ((ai % 2) + (aj % 2) + (al % 2) == 2) {
            K += 3;
            K -= 2;
        }
    }

    K += ao;
    cout << K << endl;
    return 0;
}
