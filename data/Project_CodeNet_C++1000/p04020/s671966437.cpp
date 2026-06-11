#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <functional>

using namespace std; using ll=long long; using ld=long double; using P=pair<ll,ll>; const int INF=1e9; const ll LINF=1e18;

int main() {
  int n; cin>>n;
  ll a[n];
  for(int i=0;i<n;i++) {
    cin>>a[i];
  }
  ll an=0;
  for(int i=0;i<n;i++) {
    an+=a[i]/2;
    a[i]%=2;
    if (i!=n-1&&a[i]&&a[i+1]) a[i]--, a[i+1]--, an++;
  }
  cout<<an<<endl;
}