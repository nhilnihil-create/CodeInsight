#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N, M;
  cin>>N>>M;
  vector<vector<int> > edge(N);
  int a, b;
  for(int i=0;i<M;++i) {
    cin>>a>>b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
  que.push(mp(0, 0));
  pair<int, int> state;
  int node, dist;
  int ans[N];
  for(int i=0;i<N;++i) ans[i] = -1;
  while(!que.empty()) {
    state = que.top();que.pop();
    dist = state.fi;
    node = state.se;
    if(ans[node]>-1) continue;
    ans[node] = dist;
    if(dist>=2) continue;
    for(int i=0;i<edge[node].size();++i) {
      if(ans[edge[node][i]]>-1) continue;
      que.push(mp(dist+1, edge[node][i]));
    }
  }
  if(ans[N-1]==-1) cout<<"IMPOSSIBLE"<<endl;
  else cout<<"POSSIBLE"<<endl;
}

