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
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i=0; i<N; ++i) cin >> a[i];

    // compress
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int M = (int)b.size();

    BinaryIndexedTree<ll> bitNum(M), bitSum(M);
    for (int i=1; i<N; ++i) {
        int pla = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        bitNum.add(pla, 1);
        bitSum.add(pla, a[i]);
    }
    vector<ll> res(N);
    for (int i=0; i<N; ++i) res[0] += a[i];
    int l = 0;
    for (int r=1; r<N; ++r) {
        int plaR = lower_bound(b.begin(), b.end(), a[r]) - b.begin() + 1;
        if (a[l] < a[r]) {
            int plaL = lower_bound(b.begin(), b.end(), a[l]) - b.begin() + 1;
            ll num = bitNum.sum(plaL+1, M+1), sum = bitSum.sum(plaL+1, M+1);
            res[r] = sum - num * a[l];
            res[l] -= res[r];
            l = r;
        }
        bitNum.add(plaR, -1);
        bitSum.add(plaR, a[r]);
    }
    for (ll x : res) cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
