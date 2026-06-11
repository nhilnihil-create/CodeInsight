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

int N, K;
int parent[100005];
int depth[100005];
bool ok[100005];
vector<vector<int> > edge(100005);

void getdepth(ll u, ll dist) {
  depth[u] = dist;
  for(ll i=0;i<edge[u].size();++i) {
    getdepth(edge[u][i], dist+1);
  }
  return;
}

int main() {
  cin>>N>>K;
  ll tmp;
  ll ans = 0;
  for(ll i=0;i<N;++i) {
    cin>>tmp;
    tmp--;
    if(i==0 && tmp!=0) ans++;
    if(i!=0) {
      parent[i] = tmp;
      edge[tmp].push_back(i);
    }
  }
  getdepth(0, 0);
  vector<pair<ll, ll> > arr(N);
  for(ll i=0;i<N;++i) arr[i] = mp(depth[i], i);
  sort(arr.begin(), arr.end(), greater<pair<ll, ll> >());
  ll cut;
  ll now;
  bool can;
  for(ll i=0;i<N;++i) {
    if(ok[arr[i].se]) continue;
    if(arr[i].fi<=K) continue;
    now = arr[i].se;
    can = false;
    for(ll j=0;j<K;++j) {
      if(ok[now]) {
        can = true;
        break;
      }
      ok[now] = true;
      now = parent[now];
    }
    if(!can) ans++;
  }
  cout<<ans<<endl;
}

