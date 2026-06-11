#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using vint = vector<int>;
using vll = vector<ll>;
template<typename T> using uset = unordered_set<T>;
template<typename T1, typename T2> using umap = unordered_map<T1, T2>;

constexpr int INF = (1 << 30) - 1;
constexpr ll LLINF = 1LL << 60;
constexpr int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr char el = '\n';
constexpr int mod = 1000000007;

template<typename T> T gcd(T a, T b) { return (b ? gcd(b, a % b) : a); }
template<typename T> T lcm(T a, T b) { return (a / gcd(a, b) * b); }
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

template<typename T> 
struct BIT {
    vector<T> dat;

    BIT (int n) { dat.assign(n + 1, 0); }

    void add(int k, T x) {
        for (++k; k < dat.size(); k += k & -k) dat[k] += x;
    }

    T query(int k) {
        T sum = 0;
        for (++k; k > 0; k -= k & -k) sum += dat[k];
        return (sum);
    }

    int lower_bound(T x) {
        int l, r;
        l = -1, r = dat.size();
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (query(m) >= x) r = m;
            else l = m;
        }
        return (r);
    }
};


int main() {
    int N, M;
    cin >> N >> M;

    BIT<int> tree(M + 2);
    vint L(N), R(N);
    vector<Pi> length(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
        length[i] = Pi(R[i] - L[i] + 1, i);
    }
    sort(begin(length), end(length)); 
    int cur = 0;
    for (int i = 1; i <= M; i++) {
        while (cur < N && length[cur].first < i) {
            auto idx = length[cur].second;
            tree.add(L[idx], 1);
            tree.add(R[idx] + 1, -1);
            cur++;
        }
        int cnt = 0;
        for (int j = 0; j <= M; j += i) {
            cnt += tree.query(j);
        }
        cout << (N - cur) + cnt << el;
    }

    return ( 0 );
}