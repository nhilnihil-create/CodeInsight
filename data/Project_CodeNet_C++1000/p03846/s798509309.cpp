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
using P = pair<int,int>;

const int mod = 1000000007;
int fail(){
  cout << 0 << endl;
  return 0;
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int m = (n+1)/2;
  vector<int> v(m);
  rep(i,n){
    if((n&1)==(a[i]&1)) return fail();
    int j = a[i]/2;
    if(j>=m || v[j]==2) return fail();
    v[j]++;
  }
  if((n&1)&&v[0]>1) return fail();
  int ans = 1;
  rep(i,n/2) ans = ans*2%mod;
  cout << ans << endl;
}
