#include <bits/stdc++.h>
using namespace std;
#define ll long long  
template <typename T>
bool PN(T x)
{
  if (x <= 1)
    return false;
  if (x == 2)
    return true;
  for (int i = 2; i < sqrt(x) + 1; i++)
    if (x % i == 0)
      return false;
  return true;
}

const long long MOD = 1e9+7;

void solve()
{
  int n, m; cin >> n >> m;
  int road[51][51] = {};
  for(int i = 0; i < m; ++i){
    int a, b; cin >> a >> b;
    road[a][b]++;
    road[b][a]++;
  }
  for(int i = 1; i <= n; ++i){
    int cnt = 0;
    for(int j = 1; j <= n; ++j){
      cnt += road[i][j];
    }
    cout << cnt << endl;
  }
     
}

int main()
{
  solve();
  return 0;
}