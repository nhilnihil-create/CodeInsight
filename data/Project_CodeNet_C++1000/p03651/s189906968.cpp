#include <stdio.h>

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}
#ifdef LOCAL
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

typedef long long ll;

const string DIGITS = "0123456789";
const string ALPH = "abcdefghijklmnopqrstuvwxyz";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    ll max_a = 0;
    REP(i, N) {
        cin >> A[i];
        if (A[i] == K) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
        if (A[i] > max_a) max_a = A[i];
    }
    if (max_a < K) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    set<ll> k_diff;
    REP(i, N) k_diff.insert(abs(A[i] - K));
    debug(k_diff);
    sort(A.begin(), A.end());

    vector<ll> diff;
    set<ll> s;
    REP(i, N - 1) { s.insert(A[i + 1] - A[i]); }
    debug(s);

    for (auto i : s) {
        for (auto j : k_diff) {
            debug(i, j);
            if (i != 0) {
                if (j % i == 0) {
                    cout << "POSSIBLE" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
