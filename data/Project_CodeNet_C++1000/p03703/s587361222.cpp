#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

template<class T>
class BinaryIndexedTree {
    private:
        int N;
        std::vector<T> dat;
    public:
        BinaryIndexedTree(int n) : N(n), dat(n+1, static_cast<T>(0)) {}
        // a is 1-indexed
        void add(int a, const T v) {
            while (a <= N) {
                dat[a] += v;
                a += (a & -a);
            }
        }
        // return sum of [1, a]
        // a is 1-indexed
        T sum(int a) const {
            T res = static_cast<T>(0);
            while (a > 0) {
                res += dat[a];
                a -= (a & -a);
            }
            return res;
        }
        // return sum of [a. b)
        // a and b are 1-indexed
        T sum(int a, int b) const {
            return sum(b-1) - sum(a-1);
        }
};

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i=0; i<N; ++i) cin >> a[i];

    vector<ll> b(N+1);
    for (int i=1; i<N+1; ++i) b[i] = b[i-1] + a[i-1];
    for (ll i=1; i<N+1; ++i) b[i] -= i * K;

    vector<ll> comp = b;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (int i=0; i<N+1; ++i) b[i] = lower_bound(comp.begin(), comp.end(), b[i]) - comp.begin() + 1;

    ll res = 0;
    BinaryIndexedTree<int> bit((int)comp.size());
    for (int i=0; i<N+1; ++i) {
        res += bit.sum(b[i]);
        bit.add(b[i], 1);
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
