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
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p.at(i);
    }
    vector<int> a(N), b(N);
    int M = 30000;
    for (int i = 0; i < N; i++) {
        a[i] = (i * M + 1);
    }
    for (int i = 0; i < N; i++) {
        a[p[i] - 1] += i;
    }
    for (int i = 0; i < N; i++) {
        b[i] = (N - i - 1) * M + 1;
    }
    for (int i = 0; i < N; i++) {
        cout << a[i];
        if (i != N - 1) cout << " ";
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << b[i];
        if (i != N - 1) cout << " ";
    }
    cout << endl;
}
