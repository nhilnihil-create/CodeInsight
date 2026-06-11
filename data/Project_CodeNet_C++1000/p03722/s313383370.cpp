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
  vector<vector<pair<int, ll> > > edge(N), redge(N);
  int a, b;
  ll c;
  for(int i=0;i<M;++i) {
    cin>>a>>b>>c;
    a--;
    b--;
    edge[a].push_back(mp(b, -c));
    redge[b].push_back(mp(a, -c));
  }
  bool reach0[N], reachN[N];
  for(int i=0;i<N;++i) {
    reach0[i] = false;
    reachN[i] = false;
  }
  queue<int> que;
  que.push(0);
  int node;
  while(!que.empty()) {
    node = que.front();que.pop();
    if(reach0[node]) continue;
    reach0[node] = true;
    for(int i=0;i<edge[node].size();++i) {
      if(reach0[edge[node][i].fi]) continue;
      que.push(edge[node][i].fi);
    }
  }
  que.push(N-1);
  while(!que.empty()) {
    node = que.front();que.pop();
    if(reachN[node]) continue;
    reachN[node] = true;
    for(int i=0;i<redge[node].size();++i) {
      if(reachN[redge[node][i].fi]) continue;
      que.push(redge[node][i].fi);
    }
  }
  ll ans[N];
  for(int i=0;i<N;++i) ans[i] = big;
  ans[0] = 0;
  ll cost;
  bool can = true;
  for(int i=0;i<=N;++i) {
    for(int j=0;j<N;++j) {
      if(!reach0[j] || !reachN[j]) continue;
      for(int k=0;k<edge[j].size();++k) {
        node = edge[j][k].fi;
        cost = edge[j][k].se;
        if(!reach0[node] || !reachN[node]) continue;
        if(ans[j]+cost<ans[node]) {
          if(i==N) can = false;
          else {
            ans[edge[j][k].fi] = ans[j]+cost;
          }
        }
      }
    }
  }
  if(can) cout<<-ans[N-1]<<endl;
  else cout<<"inf"<<endl;
}

