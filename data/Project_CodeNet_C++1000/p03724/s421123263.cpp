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
  int n,m,a,b;
  map<int,int> mp;
  cin >> n >> m;
  for(int i=0; i<m; i++) {
    cin >> a >> b;
    mp[a]++,mp[b]++;
  }
  for(auto p:mp) {
    if(p.second%2) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}