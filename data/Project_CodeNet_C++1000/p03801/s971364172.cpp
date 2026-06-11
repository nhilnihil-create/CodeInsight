#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<pair<ll,int>> v;
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    v.push_back(make_pair(a,i));
  }
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());

  int it=0;
  int target=n+1;
  ll ans[n+1]={};
  while(it<n){
    if(it<n-1&&v[it].first==v[it+1].first) it++;
    else{
      ll dif=0;
      if(it==n-1) dif=v[n-1].first;
      else dif=v[it].first-v[it+1].first;
      target=min(target,v[it].second);
      ans[target]+=(it+1)*dif;
      it++;
    }
  }

  for(int i=0;i<n;i++){
    cout<<ans[i]<<endl;
  }

  return 0;
}
