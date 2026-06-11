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

/* nCk for small n
    n は 50 程度まで
    計算量: O(k)
*/
long long nCk(int n, int k) {
    long long ret = 1;
    for (int i = 0; i < k; i++) {
        ret = ret * (n - i) / (i + 1);
    }
    return ret;
}

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<ll> v(N);
    map<ll, ll> m;
    for (int i = 0; i < N; i++) {
        cin >> v.at(i);
        m[v[i]]++;
    }
    sort(v.begin(), v.end(), greater<ll>());

    ll sum = 0;
    map<ll, ll> mt;
    for (int i = 0; i < A; i++) {
        sum += v[i];
        mt[v[i]]++;
    }

    ll ans = 0;
    if (mt[v[A - 1]] == A) {
        for (int i = 0; i <= B - A && m[v[A - 1]] >= mt[v[A - 1]] + i; i++) {
            ans += nCk(m[v[A - 1]], mt[v[A - 1]] + i);
        }
    } else {
        ans += nCk(m[v[A - 1]], mt[v[A - 1]]);
    }

    cout << setprecision(20) << (long double)(sum) / (long double)A << "\n";
    cout << ans << endl;
}
