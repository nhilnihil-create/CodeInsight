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
  vector<vector<pair<int, int> > > edge(N);
  int a, b, c;
  for(int i=0;i<M;++i) {
    cin>>a>>b>>c;
    a--;
    b--;
    edge[a].push_back(mp(b, c));
    edge[b].push_back(mp(a, c));
  }
  int dist[N][N];
  for(int i=0;i<N;++i) {
    for(int j=0;j<N;++j) {
      if(i==j) dist[i][j] = 0;
      else dist[i][j] = inf;
    }
  }
  for(int i=0;i<N;++i) {
    for(int j=0;j<edge[i].size();++j) {
      dist[i][edge[i][j].fi] = min(dist[i][edge[i][j].fi], edge[i][j].se);
    }
  }
  for(int k=0;k<N;++k) {
    for(int i=0;i<N;++i) {
      for(int j=0;j<N;++j) {
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
      }
    }
  }
  int ans = 0;
  for(int i=0;i<N;++i) {
    for(int j=0;j<edge[i].size();++j) {
      if(dist[i][edge[i][j].fi]<edge[i][j].se) ans++;
    }
  }
  cout<<ans/2<<endl;
}

