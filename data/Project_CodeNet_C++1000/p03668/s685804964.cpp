#include <bits/stdc++.h>

using namespace std;

vector< int > g[100000];

int dfs(int idx, int pre = -1)
{
  int ret = 0;
  for(auto &to : g[idx]) {
    if(to == pre) continue;
    ret ^= dfs(to, idx) + 1;
  }
  return (ret);
}

int main()
{
  int N;
  cin >> N;
  for(int i = 1; i < N; i++) {
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    g[X].push_back(Y);
    g[Y].push_back(X);
  }
  if(dfs(0, -1)) cout << "Alice" << endl;
  else cout << "Bob" << endl;
}