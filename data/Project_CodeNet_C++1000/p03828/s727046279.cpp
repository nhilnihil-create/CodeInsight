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
const int M = 1001;
int main() {
  int n;
  cin >> n;
  vector<ll> p(M);
  rep(i,n){
    int x = i + 1;
    int m = 2;
    for(int m=2;m*m<=x;++m){
      while(x%m==0){
        p[m]++;
        x /= m;
      }
    }
    if(x>1) p[x]++;
  }
  ll ans = 1;
  rep(i,M) ans = (ans*(p[i]+1))%mod;
  cout << ans << endl;
}
