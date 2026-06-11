#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef long long ll;

int main()	{
  ll n, m;
  cin >> n >> m;
  unordered_map<ll, vector<ll>> x;
  for (ll i = 1; i <= n; i++)	{
    x[i] = vector<ll>();
  }
  ll a, b;
  for (ll i = 0; i < m; i++)	{
    cin >> a >> b;
    x[a].push_back(b);
    x[b].push_back(a); //check this out
  }
  bool reached = false;
  for (ll i = 0; i < x[1].size(); i++)	{
    if (find(x[x[1][i]].begin(), x[x[1][i]].end(), n) == x[x[1][i]].end())	{
      continue;
    }
    else	{
      reached = true;
      break;
    }
  }
  if (reached)	{
    cout << "POSSIBLE" << endl;
  }
  else	{
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}