#include <assert.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <complex>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cout << i << "\n"

const ll MOD = 1000000007;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll n;
  bool ans = false;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  std::vector<int> a(n);
  for (int i = 0; i < (1 << 2);i++){
    for (int j = 0; j < 2;j++){
      if((i>>j)&1){
        a[j] = 0;
      }else{
        a[j] = 1;
      }
    } 
    rep(j,2,n){
      if(s[j-1]=='o'){
        a[j] = a[j - 2] ^ a[j - 1] ^ 1;
      }else{
        a[j] = a[j - 2] ^ a[j - 1];
      }
    }
    bool isCollect = true;
    if(s[n-1]=='o'){
      if((a[n-2]^a[n-1]^a[0])==0){
        isCollect = false;
      }
    }else{
      if(a[n-2]^a[n-1]^a[0]){
        isCollect = false;
      }
    }
    if (s[0] == 'o') {
      if ((a[n - 1] ^ a[1] ^ a[0]) == 0) {
        isCollect = false;
      }
    } else {
      if (a[n - 1] ^ a[1] ^ a[0]) {
        isCollect = false;
      }
    }

    if(isCollect){
      ans = true;
      break;
    }
  }

  if(ans){
    rep(i, 0, n) {
      if (a[i]) {
        std::cout << "S";
      } else {
        std::cout << "W";
      }
    }
  }else{
    std::cout << -1;
  }
  return 0;
}