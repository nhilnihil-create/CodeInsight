#include <cstdio>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <climits>
#include <bitset>

#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue

using namespace std;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
vector<int> edge[100001];
bool used[100001];

int main(int argc, char const* argv[])
{
  int n, m;
  cin >> n >> m;
  int ld, rd;
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    if(i == 0){
      ld = a;
      rd = b;
    }
    edge[a].pb(b);
    edge[b].pb(a);
  }
  used[ld] = true;
  used[rd] = true;
  deque<int> q;
  // ld
  while(true){
    q.push_front(ld);
    used[ld] = true;
    int tmp = ld;
    for(int i = 0; i < edge[ld].size(); i++){
      if(used[edge[ld][i]])continue;
      ld = edge[ld][i];
      break;
    }
    if(ld == tmp)break;
  }
  // rd
  while(true){
    q.push_back(rd);
    used[rd] = true;
    int tmp = rd;
    for(int i = 0; i < edge[rd].size(); i++){
      if(used[edge[rd][i]])continue;
      rd = edge[rd][i];
      break;
    }
    if(rd == tmp)break;
  }
  cout << q.size() << endl;
  while(!q.empty()){
    int p = q.front(); q.pop_front();
    cout << p + 1;
    if(q.size() != 0)cout << " ";
    else cout << endl;
  }
	return 0;
}
