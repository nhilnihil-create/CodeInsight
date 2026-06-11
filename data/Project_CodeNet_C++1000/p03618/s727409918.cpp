#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
  string a;
  cin >> a;
  ll n=a.size();
  ll ans=n*(n-1)/2;
  map<char,ll> mp;
  for(int i=0;i<n;++i){
    mp[a[i]]++;
  }
  for(auto p : mp){
    if(p.second>1){
      p.second--;
      while(p.second>0){
        ans-=p.second;
        p.second--;
      }
    }
  }
  ans++;
  cout << ans << endl;
  return 0;
}
