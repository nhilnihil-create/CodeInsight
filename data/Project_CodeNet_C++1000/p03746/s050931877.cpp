#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

const int N = 1e5 + 5;

vector <int> ed[N];

deque <int> ans;

int n,m,vis[N],lst[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1 ; i <= m ; i++) {
    int u,v;
    cin >> u >> v;
    ed[u].push_back(v);
    ed[v].push_back(u);
  }

  ans.push_front(1);
  
  vis[1] = 1;

  while(1) {
    bool flag = false;

    int x = ans.front(),y = ans.back();

    for (int i = lst[x] ; i < ed[x].size() ; i++) {
      int u = ed[x][i];
      lst[x]++;
      if (vis[u] == 0) {
        vis[u] = 1;
        flag = true;
        ans.push_front(u);
        break;
      }
    }

    if (flag == true)
      continue;

    for (int i = lst[y] ; i < ed[y].size() ; i++) {
      int u = ed[y][i];
      lst[y]++;
      if (vis[u] == 0) {
        vis[u] = 1;
        flag = true;
        ans.push_back(u);
        break;
      }
    }

    if (flag == false)
      break;
  }

  cout << ans.size() << "\n";

  while(ans.empty() == false) {
    cout << ans.front() << " ";
    ans.pop_front();
  }

}
