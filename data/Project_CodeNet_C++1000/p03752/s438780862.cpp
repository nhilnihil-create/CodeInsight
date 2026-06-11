/*   _/                _/                 _/_/_/   _/
  _/_/_/_/   _/_/   _/_/_/_/   _/_/    _/       _/_/
   _/     _/    _/   _/     _/    _/  _/_/_/     _/
  _/     _/    _/   _/     _/    _/  _/    _/   _/
   _/_/   _/_/       _/_/   _/_/      _/_/     _/ */
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const double pi=3.14159265358979323846;
const int inf=2e9;
const ll INF=1e18;
using P=pair<int,int>;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  ll n,k,a[20]={},ans=INF,cnt,high,x;
  cin >> n >> k;
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  for(int i=1; i<(1<<n); i++) {
    if(__builtin_popcount(i)<k||!(i&1)) {
      continue;
    }
    cnt=0;
    high=a[0];
    x=1;
    for(int j=1; j<n; j++) {
      if(x>=k) {
        break;
      }
      if(i&(1<<j)) {
        if(a[j]<=high) {
          cnt+=high+1-a[j];
          high++;
          x++;
        }
        else {
          x++;
          high=a[j];
        }
      }
      else {
        high=max(high,a[j]);
      }
    }
    ans=min(ans,cnt);
  }
  cout << ans << "\n";
}