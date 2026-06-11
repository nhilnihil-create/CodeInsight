#include <iostream>
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
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
long long int INF = 1001001001001001LL;
int inf = 1000000007;
long long int MOD = 1000000007LL;
double PI = 3.1415926535897932;

template<typename T1,typename T2>inline void chmin(T1 &a,const T2 &b){if(a>b) a=b;}
template<typename T1,typename T2>inline void chmax(T1 &a,const T2 &b){if(a<b) a=b;}

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/* do your best */

struct UnionFind{
    
    vector<int> M_par;
    vector<int> M_rank;
    vector<int> M_size;

private:
    void init(int n = 1){
        M_par.resize(n);
        M_rank.resize(n);
        M_size.resize(n);
        for(int i = 0; i < n; i++){
            M_par[i] = i;
            M_rank[i] = 0;
            M_size[i] = 1;
        }
    }

public:

    UnionFind(size_t n = 1){
        init(n);
    }

    size_t find(size_t x){
        if(M_par[x] == x) return x;
        size_t r = find(M_par[x]);
        return M_par[x] = r;
    }
    
    bool same(size_t x, size_t y){
        return find(x) == find(y);
    }

    bool unite(size_t x, size_t y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(M_rank[x] < M_rank[y]) swap(x, y);
        if(M_rank[x] == M_rank[y]) M_rank[x]++;
        M_par[y] = x;
        M_size[x] = M_size[x] + M_size[y];
        return true;
    }

    size_t size(size_t x){
        return M_size[find(x)];
    }

};

int main() {
  
  
  int n, k, l; cin >> n >> k >> l;
  UnionFind ufA(n);
  UnionFind ufB(n);

  for (int i = 0; i < k; i++) {
    int u, v; cin >> u >> v;
    u--;
    v--;
    ufA.unite(u, v);
  }

  for (int i = 0; i < l; i++) {
    int u, v; cin >> u >> v;
    u--;
    v--;
    ufB.unite(u, v);
  }
  
  map<pair<int, int>, int> mp;
  for (int i = 0; i < n; i++) {
    mp[make_pair(ufA.find(i), ufB.find(i))]++;
  }
  for (int i = 0; i < n; i++) {
    cout << mp[make_pair(ufA.find(i), ufB.find(i))] << " ";
  }
  cout << endl;

  return 0;
}
