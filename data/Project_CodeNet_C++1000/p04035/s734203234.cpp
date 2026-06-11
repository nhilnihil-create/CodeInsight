#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <map>
#include <queue>

using namespace std; using ll=long long; using P=pair<ll,ll>; const int INF=1e9; const ll LNF=1e18;

int main(){
  int n; ll l; cin>>n>>l;
  ll a[n]; for(int i=0;i<n;i++) cin>>a[i];
  ll good=-1; for(int i=0;i<n-1;i++) if (a[i]+a[i+1]>=l) good=i;

  if (good == -1) {
    cout<<"Impossible"<<endl;
    return 0;
  }

  cout<<"Possible"<<endl;
  for(int i=0;i<good;i++) {
    cout<<i+1<<endl;
  }
  for(int i=n-1;i>good;i--) {
    cout<<i<<endl;
  }
}