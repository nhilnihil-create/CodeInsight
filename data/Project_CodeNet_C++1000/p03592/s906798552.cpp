#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i < i##_len; i++)
#define ALL(x) (x).begin(), (x).end()  // sortなどの引数を省略したい
#ifdef _DEBUG
#define PRE_COMMAND             \
    std::cin.rdbuf(in.rdbuf()); \
    std::cout << fixed << setprecision(15);
#else
#define PRE_COMMAND cout << fixed << setprecision(15);
#endif
const double EPS = 1e-10, PI = acos(-1.0);
template <class T> auto MAX(T& seq) {
    return *max_element(seq.begin(), seq.end());
}
template <class T> auto MIN(T& seq) {
    return *min_element(seq.begin(), seq.end());
}
template <class T> auto SUM(T& seq) {
    T temp{0};
    auto& temp2 = temp[0];
    return accumulate(seq.begin(), seq.end(), temp2);
}
template <class T> void SORT(T& seq) { sort(seq.begin(), seq.end()); }
template <class T, class S> void SORT(T& seq, S& sort_order) {
    sort(seq.begin(), seq.end(), sort_order);
}
template <class T> void SORTR(vector<T>& seq) {
    sort(seq.begin(), seq.end(), greater<T>());
}
template <class T, class S, class R> long long pow(T n_0, S k_0, R mod_0) {
    long long n = n_0, k = k_0, mod = mod_0, now = 1;
    while (true) {
        if (k & 1) { now = now * n % mod; }
        if ((k >>= 1) == 0) { return now; }
        n = (n * n) % mod;
    }
}
template <typename T> istream& operator>>(istream& is, vector<T>& vec) {
    for (T& x : vec) is >> x;
    return is;
}

int main() {
    PRE_COMMAND
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            if (i * j + (n - i) * (m - j) == k) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}