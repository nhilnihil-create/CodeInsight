#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,int>;

vector<ll> f(ll n){
  vector<ll> c(n+1);
  c[0] = 1;
  rep(i,n) c[i+1] = c[i]*(n-i)/(i+1); 
  return c;
}
int main() {
  int n,a,b;
  cin >> n >> a >> b;
  vector<ld> v(n);
  rep(i,n) cin >> v[i];
  sort(v.begin(),v.end());
  ld s = 0;
  rep(i,a) s += v[n-1-i];
  s /= a;
  ll ans = 0;
  if(v[n-1]==v[n-a]){
    int i = lower_bound(v.begin(),v.end(),v[n-a]) - v.begin();
    vector<ll> c = f(n-i);
    for(int k=a; k<=min(n-i,b); ++k) ans += c[k];
  }else{
    int l = lower_bound(v.begin(),v.end(),v[n-a]) - v.begin();
    int r = upper_bound(v.begin(),v.end(),v[n-a]) - v.begin();
    vector<ll> c = f(r-l);
    ans += c[a-(n-r)];
  }
  printf("%.10Lf\n%lld\n",s,ans);
}