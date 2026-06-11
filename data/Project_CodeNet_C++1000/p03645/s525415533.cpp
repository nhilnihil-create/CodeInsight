#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<int> g[200005];
int main() {
  int n,m;
  cin >> n >> m;
  rep(i,m){
    int a,b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for(int u:g[1])for(int v:g[u]){
    if(v==n){
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
}
