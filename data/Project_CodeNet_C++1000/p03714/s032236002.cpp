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

int main() {
  int n;
  cin >> n;
  vector<ll> a(n*3);
  rep(i,n*3) cin >> a[i];

  vector<ll> l(n*2+1),r(n*2+1);
  priority_queue<int,vector<int>,greater<int>> lq;
  priority_queue<int> rq;
  rep(i,n*2){
    l[i+1] = l[i]+a[i];
    lq.push(a[i]);
    if(lq.size()>n) l[i+1] -= lq.top(), lq.pop();
  }
  rep(i,n*2){
    r[i+1] = r[i]+a[n*3-1-i];
    rq.push(a[n*3-1-i]);
    if(rq.size()>n) r[i+1] -= rq.top(), rq.pop();
  }
  ll ans = -1e18L;
  rep(i,n+1) ans = max(ans,l[n+i]-r[n*2-i]);
  cout << ans << endl;
}