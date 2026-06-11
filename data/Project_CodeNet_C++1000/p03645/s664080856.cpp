#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

const int INF = 1e9;

int main()
{
  int n, m;
  cin >> n >> m;
  
  vector<P> e(m);
  rep(i, m) cin >> e[i].first >> e[i].second;
  
  vector<int> d(n + 1, INF);
  d[1] = 0;
  
  rep(i, 2) rep(i, m)
  {
    int a = e[i].first, b = e[i].second;
    d[a] = min(d[a], d[b] + 1);
    d[b] = min(d[b], d[a] + 1);
  }
  
  //rep(i, n) cout << d[i+1] << " ";
  
  if(d[n] == 2) cout << "POSSIBLE\n";
  else cout << "IMPOSSIBLE\n";
  
  
  return 0;
}