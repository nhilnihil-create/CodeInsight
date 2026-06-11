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

// const ll MOD = 1e9 + 7;
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
    if (n == 1) return b /* % MOD */;
    if (n % 2 == 0) {
        return mypow(b * b /* % MOD */, n / 2);
    } else {
        return mypow(b, n - 1) * b /* % MOD */;
    }
}

ll pcnt(ll b) {
    return __builtin_popcountll(b);
}

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

ll A[100010];
vector<int> path[100010];
bool visited[100010];

ll dfs(int v) {
    visited[v] = true;

    vector<ll> chl;
    ll sum = 0;
    for (int sv : path[v]) {
        if (visited[sv]) continue;
        ll res = dfs(sv);

        if (res < 0) return -1;

        chl.push_back(res);
        sum += res;
    }

    if (chl.empty()) {
        return A[v];
    }

    if (sum < A[v] || A[v] * 2 < sum) {
        return -1;
    }

    sort(chl.begin(), chl.end());
    ll ma = chl.back();

    if (sum - ma < ma && ma > A[v]) {
        return -1;
    }

    return A[v] * 2 - sum;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    fill(visited, visited + N, false);
    for (int v = 0; v < N; ++v) {
        if (path[v].size() == 1) continue;
        cout << (dfs(v) == 0 ? "YES" : "NO") << endl;
        return 0;
    }

    cout << (A[0] == A[1] ? "YES" : "NO") << endl;
    return 0;
}
