#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int MAX_N = 100000;
int n,m;
vi g[MAX_N];
bool vis[MAX_N];

int main()
{
  cin >> n >> m;
  int a,b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;b--;
    g[a].pb(b);
    g[b].pb(a);
  }

  fill_n(vis, n, false);

  deque<int> path({a});
  vis[a] = true;

  while (any_of(all(g[path.back()]), [](int n){ return !vis[n]; })) {
    int i = 0;
    while (vis[g[path.back()][i]]) i++;
    vis[g[path.back()][i]] = true;
    path.pb(g[path.back()][i]);
  }

  while (any_of(all(g[path.front()]), [](int n){ return !vis[n]; })) {
    int i = 0;
    while (vis[g[path.front()][i]]) i++;
    vis[g[path.front()][i]] = true;
    path.push_front(g[path.front()][i]);
  }

  cout << path.size() << endl;
  for (int i = 0; i < path.size(); i++) {
    cout << path[i]+1 << (i+1==path.size() ? '\n' : ' ');
  }

  return 0;
}
