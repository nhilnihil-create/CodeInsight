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
const int inf=1e9+5;
const ll INF=1e18+5;
using P=pair<int,int>;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  int n,l,a[100005]={},x,M=0;
  cin >> n >> l;
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  for(int i=0; i<n-1; i++) {
    M=max(M,a[i]+a[i+1]);
    if(a[i]+a[i+1]>=l) {
      x=i+1;
    }
  }
  if(M<l) {
    cout << "Impossible" << "\n";
  }
  else {
    cout << "Possible" << "\n";
    for(int i=1; i<x; i++) {
      cout << i << "\n";
    }
    for(int i=n-1; i>=x; i--) {
      cout << i << "\n";
    }
  }
}