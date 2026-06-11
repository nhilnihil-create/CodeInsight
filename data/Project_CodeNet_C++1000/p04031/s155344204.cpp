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
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int ans = 1e9;
  for(int x=-100;x<=100;++x){
    int t = 0;
    rep(i,n) t+=(x-a[i])*(x-a[i]);
    ans = min(ans,t);
  }
  cout << ans << endl;
}
