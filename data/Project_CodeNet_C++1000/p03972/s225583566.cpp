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
  ll W, H;
  cin>>W>>H;
  vector<pair<ll, int> > edge;
  ll tmp;
  for(int i=0;i<W;++i) {
    cin>>tmp;
    edge.push_back(mp(tmp, 0));
  }
  for(int i=0;i<H;++i) {
    cin>>tmp;
    edge.push_back(mp(tmp, 1));
  }
  sort(edge.begin(), edge.end());
  bool ok[H+1];
  for(int i=0;i<=H;++i) ok[i] = false;
  ll num = (H+1)*(W+1)-1;
  ll ans = 0;
  int hnum=0, wnum=0;
  for(int i=0;i<W+H;++i) {
    if(num==0) break;
    if(edge[i].se==0) {
      ans += (H+1-wnum)*edge[i].fi;
      num -= H+1-wnum;
      hnum++;
    }
    else {
      ans += (W+1-hnum)*edge[i].fi;
      num -= W+1-hnum;
      wnum++;
    }
  }
  cout<<ans<<endl;
}

