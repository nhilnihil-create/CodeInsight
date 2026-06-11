// #define _GLIBCXX_DEBUG // for STL debug (optional)
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;
using ll = long long int;
using int64 = long long int;
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int INF = 1LL << 29;
const ll LONGINF = 1LL << 60;
const ll MOD = 1000000007LL;

// Union-Find 木 (Verified: AtCoder Typical Contest 001 B)
struct UnionFind {
private:
    const int n;
    int size_;
    vector<int> uf;
public:
    // 初期化 UnionFind uni(n) のように宣言すれば良い
    UnionFind(int _n) : n(_n), size_(_n), uf(_n, -1) {}
    // find (木の根を求める)
    int find(int x) {return (uf[x] < 0) ? x : uf[x] = find(uf[x]);}
    // x と y が同じ集合に属するかどうか
    bool same(int x, int y) {return find(x) == find(y);}
    // x が属する集合の要素数
    int size(int x) {return -uf[find(x)];}
    // 集合はいくつあるか
    int size()      {return size_;}
    // x と y の属する集合を併合
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) return false;
        size_--;
        if(-uf[x] < -uf[y]) swap(x, y);
        uf[x] += uf[y]; uf[y] = x;
        return true;
    }
};


void expr() {
    ll N, M; scanf("%lld%lld", &N, &M);
    vector< pair<int, int> > edges;
    for(int i=0; i<M; i++) {
        int u, v;
        scanf("%d%d", &u, &v); u--; v--;
        if(u > v) swap(u, v);
        edges.emplace_back(u, v);
    }

    vector< tuple<int, int, int, int> > edges_2d;
    for(int i=0; i<M; i++) {
        for(int j=0; j<M; j++) {
            int a0, a1; tie(a0, a1) = edges[i];
            int b0, b1; tie(b0, b1) = edges[j];
            for(int k=0; k<2; k++) {
                edges_2d.emplace_back(a0, b0, a1, b1);
                swap(b0, b1);
            }
        }
    }

    sort(edges_2d.begin(), edges_2d.end());
    UnionFind uf(N*N);
    for(auto e : edges_2d) {
        int a0, b0, a1, b1; tie(a0, b0, a1, b1) = e;
        int x = a0 * N + b0, y = a1 * N + b1;
        uf.unite(x, y);
        fprintf(stderr, "(%d, %d) <-> (%d, %d)\n", a0, b0, a1, b1);
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int x = i * N + j;
            fprintf(stderr, "%2d ", uf.find(x));
        }
        fprintf(stderr, "\n");
    }
    
    cerr << uf.size() << endl;
    exit(0);
}

int main() {
    // expr();
    
    int N, M; scanf("%d%d", &N, &M);
    vector< vector<int> > G(N);
    vector<int> visited(N, -1);
    for(int i=0; i<M; i++) {
        int u, v; scanf("%d%d", &u, &v);
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    int free_v = 0;
    vector<int> A, B;
    {
        bool bipartite = true;
        int cnt = 0;
        
        auto dfs = [&](auto&& self, int cur) -> void {
            cnt++;
            for(auto to : G[cur]) {
                if(visited[to] >= 0) {
                    bipartite &= (visited[to] ^ visited[cur]) == 1;
                }
                else {
                    visited[to] = visited[cur] ^ 1;
                    self(self, to);
                }
            }
        };
        
        for(int i=0; i<N; i++) {
            if(visited[i] >= 0) continue;
            bipartite = true;
            visited[i] = 0;
            cnt = 0;
            
            // 孤立点
            if(G[i].size() == 0) free_v++;
            else {
                dfs(dfs, i);
                if(bipartite) A.emplace_back(cnt);
                else B.emplace_back(cnt);
            }
        }
    }

    // 真面目に考慮しなくてよい箇所
    ll ans = 2LL*free_v*N - 1LL*free_v*free_v;
    // 二部グラフ同士 -> 2 箇所    
    // 二部でないグラフが交じる -> 1 箇所
    ll X = A.size(), Y = B.size();
    // fprintf(stderr, "X = %d, Y = %d\n", X, Y);
    ans += 2*X*X + 2*X*Y + Y*Y;
    cout << ans << endl;
    return 0;
}
