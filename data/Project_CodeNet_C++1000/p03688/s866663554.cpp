#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll n,kind;
  P tmp0,tmp1;
  bool can;
  cin >> n;
  ll a[n];
  map<ll,ll> mp;
  for(int i=0;i<n;i++){
    cin >> a[i];
    mp[a[i]]++;
  }
  if(mp.size()>2){
    can=false;
  }else if(mp.size()==2){
    tmp0 = *mp.begin();
    tmp1 = *(++mp.begin());
    if(abs(tmp0.first-tmp1.first)>1){
      can=false;
    }else{
      kind = max(tmp0.first,tmp1.first);
      if(tmp0.first>tmp1.first){
        can = (tmp1.second<kind)&&(2*(kind-tmp1.second)<=tmp0.second);
      }else{
        can = (tmp0.second<kind)&&(2*(kind-tmp0.second)<=tmp1.second);
      }
    }
  }else{
    tmp0 = *mp.begin();
    if(2*tmp0.first<=n||tmp0.first==n-1){
      can=true;
    }else{
      can=false;
    }
  }
  if(can){
    cout <<"Yes\n";
  }else{
    cout <<"No\n";
  }
}
