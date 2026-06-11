#include<bits/stdc++.h>

using namespace std;

const int maxn = 2000 + 10;
int n, k, dis[maxn], ansall = maxn;
bool mark[maxn];
deque < int > deq;
vector < int > adj[maxn];

int bfs( int v )
{
  int ans = 0;
  mark[v] = 1, deq.push_back(v), dis[v] = 0;
  while( deq.size() )
  {
    for( int i = 0; i < adj[deq.front()].size(); i++ )
    {
      if( mark[adj[deq.front()][i]] == 0 )
      {
        dis[adj[deq.front()][i]] = dis[deq.front()]+1;
        if( dis[adj[deq.front()][i]] > k/2 )
        {
          ans++;
        }

        deq.push_back(adj[deq.front()][i]);
        mark[adj[deq.front()][i]] = 1;
      }
    }
    deq.pop_front();
  }

  for( int i = 0; i < maxn; i++ )
    mark[i] = 0;

   return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    if( k % 2 == 0 )
    {
      int u, v;
      for( int i = 0; i < n-1; i++ )
      {
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
      }
      for( int i = 0; i < n; i++ )
      {
        ansall = min( ansall, bfs(i) );
      }
    }
    else
    {
      pair < int, int > e[n];
      for( int i = 0; i < n-1; i++ )
      {
        cin >> e[i].first >> e[i].second;
        e[i].first--, e[i].second--;
        adj[e[i].first].push_back(e[i].second);
        adj[e[i].second].push_back(e[i].first);
      }

      k--;
      for( int i = 0; i < n-1; i++ )
      {
        mark[e[i].first] = 1;
        int k1 = bfs(e[i].second);
        mark[e[i].second] = 1;
        int k2 = bfs(e[i].first);
        ansall = min( ansall, k1+k2 );
      }
    }

    cout << ansall;
    return 0;
}
