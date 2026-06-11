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
const ll INF=5e18;
typedef pair<int,int> P;
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  ll n,l,a[100005]={},pos,f=1;
  cin >> n >> l;
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  for(int i=0; i<n-1; i++) {
    if(a[i]+a[i+1]>=l) {
      f=0;
      pos=i+1;
      break;
    }
  }
  if(f) {
    cout << "Impossible" << endl;
    return 0;
  }
  cout << "Possible" << endl;
  for(int i=1; i<pos; i++) {
    cout << i << endl;
  }
  for(int i=n-1; i>=pos; i--) {
    cout << i << endl;
  }
}