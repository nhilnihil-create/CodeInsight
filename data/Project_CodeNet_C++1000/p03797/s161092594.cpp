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
  ll n,m;
  cin >> n >> m;
  ll ans;
  if(m<=n*2) ans = m/2;
  else ans = n+(m-n*2)/4;
  cout << ans << endl;
}
