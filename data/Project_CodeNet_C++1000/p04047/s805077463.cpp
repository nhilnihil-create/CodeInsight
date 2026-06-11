#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std; typedef long long ll; const int INF=1e9+7;
typedef pair<ll,ll> P;

int main() {
  int n; cin>>n; n*=2;
  int l[n]; for(int i=0;i<n;i++) cin>>l[i];
  sort(l,l+n);
  int an=0;
  for(int i=0;i<n;i+=2) {
    an+=min(l[i],l[i+1]);
  }
  cout<<an<<endl;
}