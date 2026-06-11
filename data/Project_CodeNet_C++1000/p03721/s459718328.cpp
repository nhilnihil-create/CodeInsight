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

const int inf = 1e5+1;
ll m[inf];
int main() {
  ll n,k;
  cin >> n >> k;
  rep(i,n){
    ll a,b;
    cin >> a >> b;
    m[a]+=b;
  }
  int ans;
  rep(i,inf){
    k -= m[i];
    if(k<=0){
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}
