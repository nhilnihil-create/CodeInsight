#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;
template<typename T>
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
template<typename T>
using Edges = vector<edge<T>>;
template<typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template<typename T>
using Matrix = vector<vector<T>>;

/////////////////////////////////////////////////////////////////////
const ll inf = 1LL<<60;

int main()
{
  ll sx,sy,tx,ty; cin>>sx>>sy>>tx>>ty;

  rep(i, tx-sx) cout << 'R';
  rep(i, ty-sy) cout << 'U';
  rep(i, tx-sx) cout << 'L';
  rep(i, ty-sy) cout << 'D';

  cout << 'D';
  rep(i, tx-sx+1) cout << 'R';
  rep(i, ty-sy+1) cout << 'U';
  cout << 'L';
  cout << 'U';
  rep(i, tx-sx+1) cout << 'L';
  rep(i, ty-sy+1) cout << 'D';
  cout << 'R' << endl;;

  return 0;
}
