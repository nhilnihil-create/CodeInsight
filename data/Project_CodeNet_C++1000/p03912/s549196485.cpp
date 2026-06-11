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
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N, M;
  cin>>N>>M;
  ll tmp;
  map<ll, int> amap, bmap, cmap;
  for(int i=0;i<N;++i) {
    cin>>tmp;
    amap[tmp]++;
    bmap[tmp%M]++;
  }
  for(int i=1;i<=100000;++i) {
    cmap[i%M] += amap[i]/2;
  }
  ll ans = 0;
  for(int i=0;i<M;++i) {
    if(i>M-i) break;
    if(i==0) {
      ans += bmap[i]/2;
    }
    else if(i!=M-i) {
      if(bmap[i]>bmap[M-i]) {
        ans += bmap[M-i];
        ans += min(cmap[i], (bmap[i]-bmap[M-i])/2);
      }
      else {
        ans += bmap[i];
        ans += min(cmap[M-i], (bmap[M-i]-bmap[i])/2);
      }
    }
    else {
      ans += bmap[i]/2;
    }
  }
  cout<<ans<<endl;
}

