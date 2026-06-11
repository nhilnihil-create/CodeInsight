#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;

const int INF = 1e9;

int main()
{
  int n, m;
  cin >> n >> m;
  
  vector<vector<int>> e(n, vector<int>(0));
  rep(i, m)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    e[a].emplace_back(b);
    e[b].emplace_back(a);
  }
  
  //rep(i,n){ for(auto x : e[i]) cout<<x<<" "; cout<<endl;}
  
  vector<int> d(n, INF);
  queue<int> q;
  q.push(0);
  d[0] = 0;
  
  while(q.size())
  {
    int a = q.front();
    q.pop();
    
    for(auto x : e[a])
    {
      if(d[x] == INF)
      {
        d[x] = d[a] + 1;
        q.push(x);
      }
    }
    //rep(i, n) cout << d[i] << " "; cout << endl;
  }
  //rep(i, n) cout << d[i] << endl;
  
  if(d[n-1] == 2) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
  
  
  
  return 0;
}