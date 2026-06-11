#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

using ll = long long;
using ld = long double;
const int INF = 1e15;
const double EPS = 1e-9;
const ll MOD = 1e9 + 7;

struct Node
{
  vector<int> to;
  vector<int> cost;
};
Node Graph[100010];
void AddEdge(int from, int to, int cost, Node *graph)
{
  graph[from].to.push_back(to);
  graph[from].cost.push_back(cost);
  graph[to].to.push_back(from);
  graph[to].cost.push_back(cost);
}

vector<ll> dist;

void bfs(int x)
{
  queue<int> q;
  q.push(x);
  while (!q.empty())
  {
    int p = q.front();
    q.pop();
    for (int i = 0; i < Graph[p].to.size(); ++i)
    {
      int y = Graph[p].to[i];
      if (dist[y] == INF)
      {
        dist[y] = Graph[p].cost[i] + dist[p];
        q.push(y);
      }
    }
  }
}

int main()
{
  long long N;
  scanf("%lld", &N);
  for (int i = 0; i < N - 1; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    AddEdge(a, b, c, Graph);
  }
  long long Q;
  scanf("%lld", &Q);
  long long K;
  scanf("%lld", &K);
  K--;
  dist.assign(N + 1, INF);
  dist[K] = 0;
  bfs(K);
  for (int i = 0; i < Q; i++)
  {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    cout << dist[x] + dist[y] << endl;
  }

  return 0;
}
