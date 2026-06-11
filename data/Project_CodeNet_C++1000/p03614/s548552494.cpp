#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <numeric>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <bitset>
#include <queue>

using namespace std;
typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
#define rep(i, n) for(int i = 0;i < n;i++)
const long long INF = 1LL << 60;

int MOD = 1000000007;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    int n; cin >> n;
    std::vector<int> a(n);
    rep(i,n) cin >> a[i];

    int current = a[0]; int ans=0;
    rep(i,n){
      if(current== i+1){
        ans++;
        current = a[i];
      } else{
        if(i!=n-1) current = a[i+1];
      }
    }
    cout << ans << endl;
    
    return 0;
}
