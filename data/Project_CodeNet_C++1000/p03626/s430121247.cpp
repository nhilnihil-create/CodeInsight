#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int MOD = 1e9+7;

int main(){
  int N;
  string S1, S2;
  cin >> N >> S1 >> S2;
  ll ans = 1;
  bool prev;
  rep(i, N) {
    if(S1[i] == S2[i]) {
      if(i) {
        if(!prev)
          ans = ans*2%MOD;
      }
      else
        ans = 3;
      prev = 0;
    } else {
      if(i) {
        if(prev)
          ans = ans*3%MOD;
        else
          ans = ans*2%MOD;
      }
      else
        ans = 6;
      i++;
      prev = 1;
    }
  }
  cout << ans << endl;
  return 0;
}