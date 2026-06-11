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

/* ----- Output Functions for Debugging ----- */

template <class T>
ostream& operator<<(ostream& os, vector<T> v);
template <class T>
ostream& operator<<(ostream& os, set<T> v);
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p);
template <class K, class T>
ostream& operator<<(ostream& os, map<K, T> v);
template <class T>
ostream& operator<<(ostream& os, queue<T> q);
template <class T>
ostream& operator<<(ostream& os, priority_queue<T> q);

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

/* ----- Short Functions ----- */

template <class T>
vector<T> Vec(size_t l, T v) { return vector<T>(l, v); }

template <class T, class... Ts>
auto Vec(size_t l, Ts... ts) {
    return vector<decltype(Vec<T>(ts...))>(l, Vec<T>(ts...));
}

template <class T>
inline T sq(T a) { return a * a; }

template <class T>
inline T iceil(T n, T d) { return (n + d - 1) / d; }

template <class T>
T gcd(T a, T b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

template <class T, class U>
T ipow(T b, U n) {
    T ret = 1;
    while (n > 0) {
        if (n & 1) ret *= b;
        n >>= 1;
        b *= b;
    }
    return ret;
}

// 0-indexed
template <class T, class U>
inline T kthbit(T a, U k) { return (a >> k) & 1; }

template <class T, class U>
inline T mask(T a, U k) { return a & ((1 << k) - 1); }

/* ----- Constants ----- */
// const int INF = 1 << 25;
// const ll INF = 1LL << 50;
// const ld PI = acos(-1);
// const ld EPS = 1e-10;
// mt19937 mt(ll(time(0)));

bool solve(int N, vector<int>& A) {
    cerr << A << endl;
    if (N == 1) return false;

    // 総和の偶奇
    int parity = accumulate(A.begin(), A.end(), 0, [](int init, int a) { return (init + (a & 1)) & 1; });

    // Nが偶数の場合、和の偶奇がそのまま勝敗になる
    if ((N & 1) == 0) return parity != 0;

    // Nが奇数の場合も、和が偶数なら絶対勝てる
    if (parity == 0) return true;

    // 奇数を前に持っていく
    sort(A.begin(), A.end(), [](int a, int b) { return (a & 1) > (b & 1); });
    // 奇数が複数個ある、あるいは唯一の奇数が1(減らせない)なら負け
    if (A[0] == 1 || (A[1] & 1) != 0) return false;
    // そうでなければ、唯一の奇数を減らしてワンチャンに賭ける
    --A[0];
    ll g = accumulate(A.begin(), A.end(), 0, gcd<int>);
    for (auto& a : A) a /= g;
    return !solve(N, A);
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& a : A) cin >> a;
    cout << (solve(N, A) ? "First" : "Second") << endl;
    return 0;
}
