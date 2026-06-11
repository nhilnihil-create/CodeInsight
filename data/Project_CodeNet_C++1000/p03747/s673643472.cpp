// IO library
#include <cstdio>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>

// contancer library
#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    for (auto vv : v) os << vv << ",";
    return os << "]";
}

template <class T>
ostream& operator<<(ostream& os, set<T> v) {
    os << "{";
    for (auto vv : v) os << vv << ",";
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}

template <class K, class T>
ostream& operator<<(ostream& os, map<K, T> v) {
    os << "{";
    for (auto vv : v) os << vv << ",";
    return os << "}";
}

template <class T>
ostream& operator<<(ostream& os, queue<T> q) {
    os << "[";
    while (!q.empty()) {
        os << q.front() << ",";
        q.pop();
    }
    return os << "]";
}

template <class T>
ostream& operator<<(ostream& os, priority_queue<T> q) {
    os << "{";
    while (!q.empty()) {
        os << q.top() << ",";
        q.pop();
    }
    return os << "}";
}

const ll MOD = 1000000007;
// const ll MOD = 998244353;
// const int INF = 1 << 25;
// const ll INF = 1LL << 50;
// const ld PI = acos(-1);
// const ld EPS = 1e-10;
// mt19937 mt(ll(time(0)));

template <class T>
vector<T> Vec(size_t l, T v) { return vector<T>(l, v); }

template <class T, class... Ts>
auto Vec(size_t l, Ts... ts) {
    return vector<decltype(Vec<T>(ts...))>(l, Vec<T>(ts...));
}

template <typename T>
inline T sq(T a) { return a * a; }

template <typename T>
inline T iceil(T n, T d) { return (n + d - 1) / d; }

template <typename T>
T gcd(T a, T b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

template <typename T, typename U>
T ipow(T b, U n) {
    T ret = 1;
    while (n > 0) {
        if (n & 1) ret *= b;
        n >>= 1;
        b *= b;
    }
    return ret;
}

template <typename T, typename U>
T mpow(T b, U n) {
    T ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * b % MOD;
        n >>= 1;
        b = b * b % MOD;
    }
    return ret;
}

int main() {
    ll N, L, T;
    cin >> N >> L >> T;

    auto x = Vec<ll>(N, 0LL), w = Vec<ll>(N, 0LL);
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> w[i];
        w[i] = 3 - w[i] * 2;
    }

    ll confl = 0;
    for (int i = 1; i < N; ++i) {
        if (w[0] == w[i]) continue;
        if (w[0] > 0) {
            confl += iceil(x[0] - x[i] + T * 2, L);
        } else {
            confl += iceil(x[i] - x[0] + T * 2, L) - 1;
        }
    }
    cerr << confl << endl;

    ll id0 = confl % N;
    if (w[0] < 0) id0 = (N - id0) % N;
    ll x0 = (x[0] + T * w[0]) % L;
    if (x0 < 0) x0 += L;

    for (int i = 0; i < N; ++i) {
        x[i] = (x[i] + T * w[i]) % L;
        if (x[i] < 0) x[i] += L;
    }

    sort(x.begin(), x.end());
    auto itr = lower_bound(x.begin(), x.end(), x0);
    if (w[0] < 0) itr = --upper_bound(x.begin(), x.end(), x0);

    auto ans = Vec<ll>(N, 0LL);
    for (int j = 0; j < N; ++j) {
        ans[(id0 + j) % N] = *itr;
        if (++itr == x.end()) itr = x.begin();
    }

    for (auto& e : ans) cout << e << endl;
    return 0;
}
