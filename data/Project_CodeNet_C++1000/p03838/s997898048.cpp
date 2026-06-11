#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
  ll x,y;cin >>x>>y;
  ll ans=0;
  if(abs(x)==abs(y)){
      if(x*y<0)ans=1;
      else ans=0;
  }
  else if(abs(x)<abs(y)){
      if(x<0)ans++;
      ans+=abs(y)-abs(x);
      if(y<0)ans++;
  }
  else {
      if(x>0)ans++;
      if(y>0)ans++;
      ans+=abs(x)-abs(y);
  }
  cout <<ans <<endl;
  return 0;
}

