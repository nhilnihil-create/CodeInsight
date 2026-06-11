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
    int N, M;
    cin >> N >> M;
    vector<int> X(N);
    map<int, int> m;
    for (int i = 0; i < N; i++) {
        cin >> X.at(i);
        m[X[i]]++;
    }
    vector<vector<int>> num(M);
    for (auto p : m) {
        num[p.first % M].push_back(p.second);
    }
    /*
    for (int i = 0; i < M; i++) {
        cout << i << ": ";
        for (auto v : num[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
*/
    ll ans = 0;
    ans += accumulate(ALL(num[0]), 0LL) / 2;
    for (int i = 1; i < (M + 1) / 2; i++) {
        int A = 0;
        int a = 0;
        int B = 0;
        int b = 0;
        for (auto v : num[i]) {
            A += v;
            a += v / 2 * 2;
        }
        for (auto v : num[M - i]) {
            B += v;
            b += v / 2 * 2;
        }
        if (B < A) {
            swap(A, B);
            swap(a, b);
        }
        if (B - A <= b) {
            ans += (A + B) / 2;
        } else {
            ans += b / 2;
            ans += A;
        }
        //      cout << A << " " << B << " " << ans << endl;
    }
    if (M % 2 == 0) {
        ans += accumulate(ALL(num[M / 2]), 0LL) / 2;
    }
    cout << ans << endl;
}
