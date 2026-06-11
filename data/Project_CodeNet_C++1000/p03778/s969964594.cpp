#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;


int main(){
  ll w,a,b; cin >> w >> a >> b;
  
  if((a<=b&&b<=a+w)||(b<=a&&a<=b+w)) cout << 0 << endl;
  else{
  cout << min(abs(a+w-b),abs(b+w-a)) << endl;
  }
}
  