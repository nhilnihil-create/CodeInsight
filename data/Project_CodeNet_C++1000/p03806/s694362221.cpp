#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int inf = 1001001001;
const int m = 10100;
int main() {
  int n,ma,mb;
  cin >> n >> ma >> mb;
  vector<P> l,r;
  int ans = inf;
  rep(i,n){
    int a,b,c;
    cin >> a >> b >> c;
    a *= mb; b *= ma;
    if(a==b) ans = min(ans,c);
    if(a>b) l.emplace_back(a-b,c);
    if(a<b) r.emplace_back(b-a,c);
  }
  if(ans==inf&&(l.empty()||r.empty())){
    cout << -1 << endl;
    return 0;
  }
  vector<int> dpl(m,inf), dpr(m,inf);
  dpl[0] = dpr[0] = 0;
  rep(x,int(l.size())){
    int v = l[x].first, c = l[x].second;
    rep(i,m-v) dpl[m-1-i] = min(dpl[m-1-i],dpl[m-1-v-i]+c);
  }
  rep(x,int(r.size())){
    int v = r[x].first, c = r[x].second;
    rep(i,m-v) dpr[m-1-i] = min(dpr[m-1-i],dpr[m-1-v-i]+c);
  }
  rep(i,m) if(i!=0) ans = min(ans,dpl[i]+dpr[i]);
  if(ans==inf) ans = -1;
  cout << ans << endl;
}