//   _/                _/                 _/_/_/   _/
//_/_/_/_/   _/_/   _/_/_/_/   _/_/    _/       _/_/
// _/     _/    _/   _/     _/    _/  _/_/_/     _/
//_/     _/    _/   _/     _/    _/  _/    _/   _/
// _/_/   _/_/       _/_/   _/_/      _/_/     _/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const double pi=acos(-1);
const int inf=1e9;
const ll INF=1e18;
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  int h,w,n,ans[105][105]={},a[10005]={},now=1;
  cin >> h >> w >> n;
  for(int i=1; i<=n; i++) {
    cin >> a[i];
  }
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      if(i%2==0) {
        ans[i][j]=now;
        a[now]--;
        if(!a[now]) {
          now++;
        }
      }
      else {
        ans[i][w-j-1]=now;
        a[now]--;
        if(!a[now]) {
          now++;
        }
      }
    }
  }
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}
