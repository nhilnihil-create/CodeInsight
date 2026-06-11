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
  int N;
  cin>>N;
  vector<pair<ll, int> > arr;
  map<ll, ll> amap;
  ll tmp;
  for(int i=0;i<N;++i) {
    cin>>tmp;
    if(amap[tmp]==0) arr.push_back(mp(tmp, i));
    amap[tmp]++;
  }
  priority_queue<tuple<ll, int, ll> > que;
  for(int i=0;i<arr.size();++i) {
    que.push(mt(arr[i].fi, arr[i].se, amap[arr[i].fi]));
  }
  ll ans[N];
  for(int i=0;i<N;++i) ans[i] = 0;
  tuple<ll, int, ll> state1, state2;
  while(!que.empty()) {
    if(que.size()==1) {
      state1 = que.top();que.pop();
      ans[get<1>(state1)] += get<2>(state1)*get<0>(state1);
    }
    else {
      state1 = que.top();que.pop();
      state2 = que.top();que.pop();
      ans[get<1>(state1)] += get<2>(state1)*(get<0>(state1)-get<0>(state2));
      if(get<1>(state1)>get<1>(state2)) {
        state1 = mt(get<0>(state2), get<1>(state2), get<2>(state1)+get<2>(state2));
      }
      else {
        state1 = mt(get<0>(state2), get<1>(state1), get<2>(state1)+get<2>(state2));
      }
      que.push(state1);
    }
  }
  for(int i=0;i<N;++i) cout<<ans[i]<<endl;
}

