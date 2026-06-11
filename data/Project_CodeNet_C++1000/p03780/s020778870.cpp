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
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  int l = -1, r = n;
  while(l+1<r){
    int c = (l+r)/2;
    if(a[c]>=k){
      r = c;
      continue;
    }
    int x = lower_bound(a.begin(),a.end(),a[c]) - a.begin();
    vector<bool> dp(k);
    dp[a[x]] = true;
    int res = 1001001001;
    rep(i,n){
      if(i==x) continue;
      int v = a[i];
      rep(jj,k){
        int j = k-1-jj;
        if(!dp[j]) continue;
        if(j+v<k) dp[j+v] = true;
        else res = min(res,(j+v)-k);
      }
    }
    if(res<a[x]) r = c;
    else l = c;
  }
  cout << l+1 << endl;
}