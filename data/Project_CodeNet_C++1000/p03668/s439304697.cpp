#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005

int N;
vector<int> Edge[MAX_N];

int dfs(int pos, int pre)
{
  int ret = 0;
  for (int i = 0; i < Edge[pos].size(); i++) {
    int next = Edge[pos][i];
    if(next == pre){
      continue;
    }
    ret ^= (dfs(next, pos) + 1);
  }

  return ret;
}

int main()
{
  cin >> N;
  for (int i = 0; i < N-1; i++) {
    int x, y; cin >> x >> y; x--; y--;
    Edge[x].push_back(y);
    Edge[y].push_back(x);
  }

  if(dfs(0, -1) == 0){
    cout << "Bob" << endl;
  }
  else{
    cout << "Alice" << endl;
  }

  return 0;
}
