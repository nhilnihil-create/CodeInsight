#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,s,e) for (int i=s;i<(e);i++)
#define All(v) (v).begin(),(v).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;
typedef long long llint;
typedef pair<int, int> P;
const int MOD = (int)1e9 + 7;
const int INF = 999999999;

struct UnionFind
{
  vector< int > data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  bool unite(int x, int y)
  {
    x = root(x), y = root(y);
    if(x == y) return false;
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }

  int root(int k)
  {
    if(data[k] < 0) return(k);
    return (data[k] = root(data[k]));
  }

  int size(int k)
  {
    return -data[root(k)];
  }
};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K, L;
    cin >> N >> K >> L;

    
    UnionFind road(N);
    UnionFind rail(N);

    REP(i, K){
        int p, q;
        cin >> p >> q;
        p--; q--;
        road.unite(p, q);
    }
    REP(i, L){
        int p, q;
        cin >> p >> q;
        p--; q--;
        rail.unite(p, q);
    }
    map<P, int> m;
    REP(i, N){
        m[mp(road.root(i), rail.root(i))]++;
    }
    REP(i, N){
        cout << m[mp(road.root(i), rail.root(i))] << (i == N-1 ? "\n":" ");
    }

    return 0;
}