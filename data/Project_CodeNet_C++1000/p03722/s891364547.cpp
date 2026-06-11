#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

typedef long long ll;
// constexpr ll MOD = 998244353;
constexpr ll MOD = 1000000007;

// struct UnionFind {
//     vector<int> par;
    
//     UnionFind(int N): par(N) {
//         for (int i=0;i<N;i++) par[i] = i;
//     }

//     int root(int x) {
//         if (par[x] == x) return x;
//         else return par[x] = root(par[x]);
//     }

//     void unite(int x, int y) {
//         int rx = root(x);
//         int ry = root(y);
//         if (rx == ry) return;
//         par[rx] = ry;
//     }

//     bool same(int x, int y) {
//         int rx = root(x);
//         int ry = root(y);
//         return rx == ry;
//     }
// };

int main(void) {
    int N, M;
    cin >> N >> M;
    vector<tuple<int,int,ll>> E(2010); // source, dest, weight
    for (int i=0;i<M;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        E[i] = make_tuple(a,b,-c);
    }
    vector<pair<int,ll>> V(1010); // predecessor, distance
    V[1] = make_pair(0,0);
    for (int j=2;j<=N;j++) {
        V[j] = make_pair(0,1LL<<60);
    }
    for (int j=1;j<N;j++) {
        for (int i=0;i<M;i++) {
            int source, dest; ll cost;
            tie(source, dest, cost) = E[i];
            if (V[dest].second > V[source].second + cost) {
                V[dest].second = V[source].second + cost;
                V[dest].first = source;
            }
        }
    }
    vector<bool> negloop(1010,false);
    for (int j=1;j<=N;j++) {
        for (int i=0;i<M;i++) {
            int source, dest; ll cost;
            tie(source, dest, cost) = E[i];
            if (V[source].second + cost < V[dest].second) {
                V[dest].second = V[source].second + cost;
                negloop[dest] = true;
            }
            if (negloop[source]) negloop[dest] = true;
        }
    }
    if (negloop[N]) cout << "inf" << endl;
    else cout << -V[N].second << endl;

    return 0;
}
