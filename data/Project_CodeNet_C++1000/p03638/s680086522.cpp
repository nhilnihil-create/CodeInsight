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
const int INF = 2100100100;
// const int MOD = 1e9 + 7;

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }

    auto c = make_vec<int>(H, W);
    int now = 0;
    for (int i = 0; i < H; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < W; j++) {
                if (a[now] == 0) now++;
                c[i][j] = now + 1;
                a[now]--;
            }
        } else {
            for (int j = W - 1; j >= 0; j--) {
                if (a[now] == 0) now++;
                c[i][j] = now + 1;
                a[now]--;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << c[i][j];
            if (j != W - 1) cout << " ";
        }
        cout << endl;
    }
}
