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
  int n,t;
  cin >> n >> t;
  ll ans = 0, c = 0;
  rep(i,n){
    ll a;
    cin >> a;
    if(a<c) ans -= c-a;
    ans += t;
    c = a+t;
  }
  cout << ans << endl;
}
