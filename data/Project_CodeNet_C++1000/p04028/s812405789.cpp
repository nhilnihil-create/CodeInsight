/* ---------- STL Libraries ---------- */

// IO library
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

/* ---------- Namespace ---------- */

using namespace std;

/* ---------- Type Abbreviation ---------- */

template <typename T>
using PQ = priority_queue<T>;
template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

using ll = long long;

#define fst first
#define snd second
#define mp make_pair
#define mt make_tuple

/* ---------- conversion ---------- */

#define INT(c) static_cast<int>(c)
#define CHAR(n) static_cast<char>(n)
#define LL(n) static_cast<ll>(n)
#define DOUBLE(n) static_cast<double>(n)

/* ---------- container ---------- */

#define ALL(v) (v).begin(), (v).end()
#define SIZE(v) (LL((v).size()))

#define FIND(v, k) (v).find(k) != (v).end()
#define VFIND(v, k) find(ALL(v), k) != (v).end()

#define gsort(b, e) sort(b, e, greater<decltype(*b)>())

/* ----------- debug ---------- */

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class T>
ostream& operator<<(ostream& os, set<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.fst << "," << p.snd << ")";
}

/* ---------- Constants ---------- */

const ll MOD = 1e9 + 7;
// const int INF = 1 << 25;
// const ll INF = 1LL << 50;
// const double PI = acos(-1);
// const double EPS = 1e-10;
// mt19937 mert(LL(time(0)));

/* ---------- Short Functions ---------- */

template <typename T>
T sq(T a) {
    return a * a;
}

template <typename T>
T gcd(T a, T b) {
    if (a > b) return gcd(b, a);
    return a == 0 ? b : gcd(b % a, a);
}

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b % MOD;
    if (n % 2 == 0) {
        return mypow(b * b % MOD, n / 2);
    } else {
        return mypow(b, n - 1) * b % MOD;
    }
}

ll pcnt(ll b) {
    return __builtin_popcountll(b);
}

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

int main() {
    int N, K;
    string S;
    cin >> N >> S;
    K = S.length();

    ll dp[N + 1];
    fill(dp, dp + N + 1, 0);
    dp[0] = 1;
    // dp[i] = i文字打たれているパターン数

    for (int q = 0; q < N; ++q) {
        ll ndp[N + 1];
        fill(ndp, ndp + N + 1, 0);

        for (int i = 0; i < N; ++i) {
            ndp[i + 1] += dp[i] * 2;
            ndp[max(0, i - 1)] += dp[i];
        }

        for (int i = 0; i <= N; ++i) {
            dp[i] = ndp[i] % MOD;
        }
    }

    cout << dp[K] * mypow(mypow(2LL, K), MOD - 2) % MOD << endl;

    return 0;
}
