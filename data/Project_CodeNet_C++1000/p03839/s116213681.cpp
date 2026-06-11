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

/*  divisor(n)
    入力：整数 n
    出力：nのすべての約数
    計算量：O(√n)
*/
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int N, M, K, Q, W, H, L, R, C, A, B, D;
string S;
vector<vector<int>> X;

int main() {
    cin >> N >> K;
    vector<ll> a(N), sum(N + 1), plu(N + 1), sub(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
        sum[i + 1] = sum[i] + a[i];
        plu[i + 1] = plu[i] + max(a[i], 0LL);
        sub[i + 1] = sub[i] + min(a[i], 0LL);
    }

    ll ans = sum[N];
    for (int i = 0; i <= N - K; i++) {  // white
        /* code */
        chmax(ans, plu[N] - (plu[i + K] - plu[i]));
    }
    for (int i = 0; i <= N - K; i++) {  // black
        /* code */
        chmax(ans, plu[N] + (sub[i + K] - sub[i]));
    }
    cout << ans << endl;

    return 0;
}
