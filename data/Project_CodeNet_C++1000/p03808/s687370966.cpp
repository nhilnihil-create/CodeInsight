#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
 
using namespace std;
using LL = long long;
 
int main(void)
{
  LL n;
  cin >> n;
  vector<LL> v(n);
  LL sum=0,once=n*(n+1)/2;
  for(auto &x: v) cin >> x;
  for(auto x:v) sum+=x;
  bool flag = true;
  if(sum%once) flag = false;
  LL times = sum/once;
  REP(i,n) {
    LL diff = v[(i+1)%n] - v[i];
    diff -= times;
    if(diff%n) flag = false;
    if(diff>0) flag = false;
  }
  
  cout << (flag?"YES":"NO") << endl;
  return 0;
}
