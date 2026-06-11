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

class BinaryIndexedTree {
    using T = pair<ll, ll>;
    private:
        int N;
        std::vector<T> dat;
    public:
        BinaryIndexedTree(int n) : N(n), dat(n+1) {}
        // a is 1-indexed
        void add(int a, const T v) {
            while (a <= N) {
                dat[a].first += v.first;
                dat[a].second += v.second;
                a += (a & -a);
            }
        }
        // return sum of [1, a]
        // a is 1-indexed
        T sum(int a) const {
            T res = make_pair(0LL, 0LL);
            while (a > 0) {
                res.first += dat[a].first;
                res.second += dat[a].second;
                a -= (a & -a);
            }
            return res;
        }
        // return sum of [a. b)
        // a and b are 1-indexed
        T sum(int a, int b) const {
            T res = make_pair(0LL, 0LL);
            T tmpb = sum(b-1), tmpa = sum(a-1);
            res.first = tmpb.first - tmpa.first;
            res.second = tmpb.second - tmpa.second;
            return res;
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

    BinaryIndexedTree bit(M);
    for (int i=1; i<N; ++i) bit.add(lower_bound(b.begin(), b.end(), a[i])-b.begin()+1, {1, a[i]});
    vector<ll> res(N);
    for (int i=0; i<N; ++i) res[0] += a[i];
    int l = 0;
    for (int r=1; r<N; ++r) {
        int cur = lower_bound(b.begin(), b.end(), a[r]) - b.begin() + 1;
        if (a[l] < a[r]) {
            auto p = bit.sum(lower_bound(b.begin(), b.end(), a[l])-b.begin()+2, M+1);
            ll num = p.first, sum = p.second;
            res[r] = sum - num * a[l];
            res[l] -= res[r];
            l = r;
        }
        bit.add(cur, {-1, -a[r]});
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
