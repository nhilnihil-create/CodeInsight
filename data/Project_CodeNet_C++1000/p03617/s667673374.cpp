
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <functional>

using namespace std; using ll=long long; using ld=long double; using P=pair<ll,ll>; const int INF=1e9; const ll LINF=1e18;

int main(){
  ll q,h,s,d; cin>>q>>h>>s>>d;
  s = min(q*4, min(h*2, s));
  ll n; cin>>n;
  if (n%2==0) {
    cout<<min(n*s,n*d/2)<<endl;
  } else {
    cout<<min(n*s,(n/2)*d+s)<<endl;
  }
}