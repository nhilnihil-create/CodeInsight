
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

const int MAX_UF = MAX_N;

class UnionFind {
private:
  int par[MAX_UF];
  int rank[MAX_UF];
  
public:
  int find(int x);
  void init(int n);
  void unite(int x, int y);
  bool same (int x, int y);
};

void UnionFind::init(int n) {
  for (int i = 0; i < n; ++i) {
    par[i] = i;
    rank[i] = 0;
  }
}

int UnionFind::find(int x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}

void UnionFind::unite(int x, int y) {
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

bool UnionFind::same(int x, int y) {
  return find(x) == find(y);
}

vector<int> group[MAX_N];

int main() {
  cin >> N >> K >> L;

  UnionFind road_uinion;
  UnionFind rail_uinion;
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

  map<pii, int> duplicate;
  for (int i = 0; i < N; ++i) {
    group[road_uinion.find(i)].push_back(rail_uinion.find(i));
  }

  for (int i = 0; i < N; ++i) {
    sort(all(group[i]));
  }

  for (int i = 0; i < N; ++i) {
    cout << upper_bound(all(group[road_uinion.find(i)]), rail_uinion.find(i)) - lower_bound(all(group[road_uinion.find(i)]), rail_uinion.find(i)) << endl;
  }

}
