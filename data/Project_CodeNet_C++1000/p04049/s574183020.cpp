/// awoooooo

# include <bits/stdc++.h>

# define sz(x) (int)((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;

const int N = (int)2e5 + 5;
const int inf = (int)1e9 + 7;

int n, k;
int d[N];
vector < int > g[N];
vector < pii > edges;
pii ban;

void dfs(int v, int p){
  for(int i : g[v]){
    if(i == p || i == ban.first || i == ban.second){
      continue;
    }
    d[i] = d[v] + 1;
    dfs(i, v);
  }
}

int main(){
  scanf("%d %d", &n, &k);
  for(int i = 1; i < n; ++i){
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
    edges.push_back(make_pair(a, b));
  }
  int ans = n;
  if(k % 2 == 0){
    for(int i = 1; i <= n; ++i){
      d[i] = 0;
      dfs(i, i);
      int cur = 0;
      for(int j = 1; j <= n; ++j){
        cur += d[j] > k / 2;
      }
      ans = min(ans, cur);
    }
  } else{
    for(auto i : edges){
      ban = make_pair(i.first, i.second);
      d[i.first] = 0;
      d[i.second] = 0;
      dfs(i.first, i.first);
      dfs(i.second, i.second);
      int cur = 0;
      for(int j = 1; j <= n; ++j){
        cur += d[j] > k / 2;
      }
      ans = min(ans, cur);
    }
  }
  printf("%d\n", ans);
  return 0;
}
