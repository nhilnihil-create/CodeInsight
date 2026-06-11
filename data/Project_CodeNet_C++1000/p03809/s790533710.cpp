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
 
int main() {
    int N; scanf("%d", &N);
    vector<bool> is_leaf(N);
    vector<ll> val(N), deg(N);
    
    vector<ll> A(N);
    for(int i=0; i<N; i++) scanf("%lld", &A[i]);

    vector< vector< pair<int, int> > > G(N);
    for(int i=0; i+1<N; i++) {
        int u, v; scanf("%d%d", &u, &v);
        u--; v--;
        G[u].emplace_back(v, i);
        G[v].emplace_back(u, i);
        deg[u]++; deg[v]++;
    }

    if(N == 2) {
        if(A[0] == A[1]) puts("YES");
        else puts("NO");
        return 0;
    }

    for(int i=0; i<N; i++) is_leaf[i] = (deg[i] == 1);

    auto dfs = [&](auto &&self, int cur, int par) -> ll {
        ll sum = 0;
        for(auto e : G[cur]) {
            int to = e.first, k = e.second;
            if(to == par) continue;
            ll v_child = self(self, to, cur);
            val[k] = v_child;
            sum += v_child;
        }
        if(is_leaf[cur]) return A[cur];
        return 2*A[cur] - sum;
    };

    dfs(dfs, 0, -1);
    bool valid = true;
    for(int i=0; i<N; i++) {
        ll sum = 0;
        for(auto e : G[i]) {
            int j = e.first, k = e.second;
            sum += val[k];
            valid &= (val[k] >= 0);
        }

        if(is_leaf[i]) valid &= (sum == A[i]);
        else {
            valid &= (sum == 2*A[i]);
            for(auto e : G[i]) {
                int j = e.first, k = e.second;
                valid &= (2 * val[k] <= sum);
            }
        }
    }
    cout << (valid ? "YES" : "NO") << endl;
    return 0;
}

