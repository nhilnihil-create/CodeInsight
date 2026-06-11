#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main(){
  int n;
  cin>>n;
  vector<pair<long long, long long>> ab(n);
  for(int i=0;i<n;i++)cin>>ab[i].first>>ab[i].second;
  ab.emplace_back(0,10000000000000LL);
  ab.emplace_back(10000000000000LL,0);
  sort(ab.begin(),ab.end());
  long long ans=0;
  for(int i=0;i<=n;i++)ans+=min(abs(ab[i].first-ab[i+1].first),abs(ab[i].second-ab[i+1].second));
  cout<<ans<<endl;
}
