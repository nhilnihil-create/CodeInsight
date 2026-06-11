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
const int INF = 2100100100;
// const int MOD = 1e9 + 7;
using P = pair<int, int>;
int main() {
    int N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    vector<int> a(N), b(N), c(N);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i) >> b.at(i) >> c.at(i);
    }

    vector<P> A;
    for (int bit = 0; bit < (1 << (N / 2)); bit++) {
        int ma = 0;
        int mb = 0;
        int sum = 0;
        for (int i = 0; i < (N / 2); i++) {
            int mask = 1 << i;
            if (bit & mask) {
                ma += a[i];
                mb += b[i];
                sum += c[i];
            }
        }
        A.push_back(P(Ma * mb - ma * Mb, sum));
    }
    sort(A.begin(), A.end());

    int ans = INF;
    for (int bit = 0; bit < (1 << (N - N / 2)); bit++) {
        int ma = 0;
        int mb = 0;
        int sum = 0;
        for (int i = 0; i < (N - N / 2); i++) {
            int mask = 1 << i;
            if (bit & mask) {
                ma += a[i + N / 2];
                mb += b[i + N / 2];
                sum += c[i + N / 2];
            }
        }
        int C = ma * Mb - Ma * mb;

        auto it = lower_bound(ALL(A), P(C, 0));
        int l = it - A.begin();
        int num = upper_bound(ALL(A), P(C, INF)) - it;
        /*
        debug(l);
        debug(num);
        debug(ma);
        debug(mb);
        debug(sum);
        */
        for (int i = l; i < l + num; i++) {
            if (A[i].second + sum == 0) continue;
            chmin(ans, A[i].second + sum);
            break;
        }
    }
    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
