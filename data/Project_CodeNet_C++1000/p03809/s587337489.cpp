#include <iostream>
#include <bitset>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);i <= (e);(i)++)
#define int long long

#define space(x) (x) << " "

int N;
vector<vector<int>> edges;

vector<i64> A;

i64 dfs(int v,int f){
  i64 MAX = -1;
  i64 SUM = 0;
  for(int to : edges[v]){
    if(f != to){
      i64 dp = dfs(to,v);

      if(dp == -1) return -1;
      MAX = max(MAX,dp);
      SUM += dp;
    }
  }

  if(MAX == -1){
    return A[v];
  }

  i64 Y = SUM - A[v];
  i64 X = A[v] - Y;

  i64 able = SUM / 2;
  if(MAX > able){
    able = SUM - MAX;
  }
 
  if(!(X >= 0 && Y >= 0 && able >= Y)){
    return -1;
  }

  return X;
}

bool solve(){
  if(N == 2){
    return A[0] == A[1];
  }
  rep(i,0,N - 1){
    if(edges[i].size() > 1) return dfs(i,-1) == 0;
  }
}
signed main(){
  cin >> N;
  edges.resize(N);
  A.resize(N);
  rep(i,0,N - 1){
    cin >> A[i];
  }
  rep(i,1,N - 1){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  if(solve()){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }

  return 0;
}

