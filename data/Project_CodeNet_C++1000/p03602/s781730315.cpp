#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define INF 1007654321
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }
template<typename U, typename V>
ostream& operator<<(ostream &os, const pair<U, V> &p) { return os << "(" << p.first << "," << p.second << ")";}

const int MAXN = 300;
ll A[MAXN][MAXN], D[MAXN][MAXN];
struct Edge {
    int u, v; ll d;  
    bool operator<(const Edge &rhs) const {
        if(d == rhs.d) {
            if(u == rhs.u) return v < rhs.v;
            return u < rhs.u;
        }
        return d < rhs.d;
    }
};

int main() {
    FAST_IO();
    int N; cin >> N;
    rep(i, N) rep(j, N) cin >> A[i][j];
    rep(i, N) rep(j, N) D[i][j] = A[i][j];
    rep(k, N) rep(i, N) rep(j, N) {
        A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
    }
    rep(i, N) rep(j, N) {
        if(A[i][j] != D[i][j]) {
            cout << "-1\n";
            return 0;
        }
    }
    rep(i, N) rep(j, N) D[i][j] = INT_MAX;
    rep(i, N) D[i][i] = 0;
    vector<Edge> edges;
    rep(i, N) for(int j = i + 1; j < N; ++j) {
        edges.push_back({i, j, A[i][j]});
    }
    sort(all(edges));
    ll sum = 0;
    for(auto &e : edges) {
        if(D[e.u][e.v] > e.d) {
            D[e.u][e.v] = e.d;
            rep(i, N) rep(j, N) {
                D[i][j] = min(D[i][j], min(D[i][e.u] + e.d + D[e.v][j], D[i][e.v] + e.d + D[e.u][j]));
            }
            sum += e.d;
        }
    }
    cout << sum << "\n";
}
