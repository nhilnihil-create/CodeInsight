
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
#define all(X) (X).begin(),(X).end()
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX_N = 100000;
int N;
vector<int> G[MAX_N];
bool visited[MAX_N];

int serch_path(int u, vector<int> &v) {
  if (u == 0) {
    v.push_back(0);
    return 0;
  }
  visited[u] = true;
  for (int i = 0; i < G[u].size(); ++i) {
    if (!visited[G[u][i]]) {
      if (serch_path(G[u][i], v) >= 0) {
        v.push_back(u);
        return u;
      }
    }
  }
  return -1;
}

ll dfs(int u) {
  visited[u] = true;
  ll res = 0;
  for (int i = 0; i < G[u].size(); ++i) {
    if (!visited[G[u][i]]) {
      res += dfs(G[u][i]);
    }
  }
  return res+1;
}

int main() {
  cin >> N;
  rep(i, N-1) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<int> direct_path;
  serch_path(N-1, direct_path);


  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < direct_path.size(); ++i) visited[direct_path[i]] = true;

  ll sunuke = 0;
  int size = direct_path.size();
  int sn = size / 2;
  for (int i = 0; i < sn; ++i) sunuke += dfs(direct_path[size-i-1]);


  if (sunuke >= N-sunuke) cout << "Snuke" << endl;
  else cout << "Fennec" << endl;
}
