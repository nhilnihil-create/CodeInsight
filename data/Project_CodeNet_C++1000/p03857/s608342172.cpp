
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<complex>
#include<sstream>
#include<climits>
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N = 200000;
int N, K, L;

static const int MAX_UF = MAX_N;

template <class T> class UnionFind {
private:
  T par[MAX_UF];
  T rank[MAX_UF];
  
public:
  T find(T x);
  void init(T n);
  void unite(T x, T y);
  bool same (T x, T y);
};

template <class T> void UnionFind<T>::init(T n) {
  for (T i = 0; i < n; ++i) {
    par[i] = i;
    rank[i] = 0;
  }
}

template <class T> T UnionFind<T>::find(T x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}

template <class T> void UnionFind<T>::unite(T x, T y) {
  x = find(x); y = find(y);
  if (x == y) {
    return;
  } else {
    if (rank[x] > rank[y]) {
      par[y] = x;
    } else {
      par[x] = y;
      if (rank[x] == rank[y]) ++rank[y];
    }
  }
}

template <class T> bool UnionFind<T>::same(T x, T y) {
  return find(x) == find(y);
}

int main() {
  cin >> N >> K >> L;

  UnionFind<int> road_uinion;
  UnionFind<int> rail_uinion;
  road_uinion.init(N);
  rail_uinion.init(N);
  for (int i = 0; i < K; ++i) {
    int p, q;
    cin >> p >> q;
    road_uinion.unite(--p, --q);
  }
  for (int i = 0; i < L; ++i) {
    int r, s;
    cin >> r >> s;
    rail_uinion.unite(--r,--s);
  }

  map<pii, int> group;
  for (int i = 0; i < N; ++i) {
    ++group[pii(road_uinion.find(i), rail_uinion.find(i))];
  }


  for (int i = 0; i < N; ++i) {
    cout << group[pii(road_uinion.find(i), rail_uinion.find(i))] << endl;
  }

}
