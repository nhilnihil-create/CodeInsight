#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll n;
  cin >> n;
  map<ll,ll> a;
  vector<ll> m;
  for(ll i=0;i<n;++i){
    ll num;
    cin >> num;
    a[num]++;
    if( a[num] == 1 ) m.push_back(num);
  }
  sort(m.begin(),m.end());
  reverse(m.begin(),m.end());
  ll cnt = 0;
  ll ans = 1;
  ll ans2 = 0;
  for(ll i=0;i<a.size();++i){
    ll num = m.at(i);
    if( a[num] >= 4 && ans2 == 0 ){
      ans2 = num*num;
    }
    if( a[num] >= 2 && cnt != 2 ){
      cnt++;
      ans *= num;
    }
  }
  if( cnt != 2 && ans2 == 0 ){
    cout << 0 << endl;
  }else{
    cout << max(ans,ans2) << endl;
  }
  return 0;
}