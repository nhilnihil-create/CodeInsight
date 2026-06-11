#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9 + 7;
const int INF = 2e18;

template< typename T >
struct edge {
    int src, to;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}

    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge &operator=(const int &x) {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

template< typename T >
void warshall_floyd(Matrix< T > &g) {
    for(int k = 0; k < g.size(); k++) {
        for(int i = 0; i < g.size(); i++) {
            for(int j = 0; j < g.size(); j++) {
                if(g[i][k] == INF || g[k][j] == INF) continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}


signed main() {
    int N, M, R;
    cin >> N >> M >> R;
    vector<int> r(R);
    cin >> r;
    Matrix<int> mat(N + 1, vector<int>(N + 1, INF));
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        mat[A][B] = C;
        mat[B][A] = C;
    }
    warshall_floyd(mat);
    int ans = INF;
    sort(r.begin(), r.end());
    do {
        int temp = 0;
        for (int i = 0; i < R - 1; i++) {
            temp += mat[r[i]][r[i + 1]];
        }
        ans = min(ans, temp);
    } while (next_permutation(r.begin(), r.end()));
    cout << ans << endl;
}
