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
const double pi=3.14159265358979323846;
const int inf=1e9;
const ll INF=1e18;
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  ll n,l,a[100005]={},x,f=0;
  cin >> n >> l;
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  for(int i=0; i<n-1; i++) {
    if(a[i]+a[i+1]>=l) {
      x=i,f=1;
      break;
    }
  }
  if(!f) {
    cout << "Impossible" << endl;
    return 0;
  }
  cout << "Possible" << endl;
  for(int i=0; i<x; i++) {
    cout << i+1 << endl;
  }
  for(int i=n-2; i>=x; i--) {
    cout << i+1 << endl;
  }
}