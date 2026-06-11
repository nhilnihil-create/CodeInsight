#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct UnionFind{
  vector<int> data;
  UnionFind(int n) : data(n, -1) {}
  bool unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y){
      if(data[y] < data[x]) swap(x,y);
      data[x] += data[y];
      data[y] = x;
    }
    return x != y;
  }
  bool same(int x, int y){ return find(x) == find(y); }
  int find(int x){
    if(data[x] < 0) return x;
    return data[x] = find(data[x]);
  }
};


int main(){
  int N, K, L;
  cin >> N >> K >> L;
  UnionFind road(N), rail(N);
  for(int i = 0; i < K; ++i){
    int p, q;
    cin >> p >> q;
    road.unite(p-1, q-1);
  }
  for(int i = 0; i < L; ++i){
    int r, s;
    cin >> r >> s;
    rail.unite(r-1, s-1);
  }
  map< pair<int, int> , int> M;
  for(int i = 0; i < N; ++i) ++M[make_pair(road.find(i), rail.find(i))];
  for(int i = 0; i < N-1; ++i) cout << M[make_pair(road.find(i), rail.find(i))] << " ";
  cout << M[make_pair(road.find(N-1), rail.find(N-1))] << endl;
  return 0;
}
