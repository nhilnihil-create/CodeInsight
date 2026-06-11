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

ll comb[60][60];
void initComb() {
  comb[0][0] = 1;
  rep(i, 55) rep(j, i+1){
    comb[i+1][j] += comb[i][j];
    comb[i+1][j+1] += comb[i][j];
  }
}

int main(){
  initComb();
  int N, A, B;
  cin >> N >> A >> B;
  vector<ll> v(N);
  map<int, int> mp;
  rep(i, N) {
    cin >> v[i];
    mp[v[i]]++;
  }
  sort(v.rbegin(), v.rend());
  ll sum = 0;
  bool same = true;
  int cnt = 1;
  rep(i, A) {
    sum += v[i];
    if(i) {
      if(v[i] == v[i-1])
        cnt++;
      else {
        same = false;
        cnt = 1;
      }
    }
  }
  if(same) {
    ll ans = 0;
    for(int i=A; i<=B; i++)
      ans += comb[mp[v[A-1]]][i];
    cout << fixed << setprecision(6) << sum/(double)A << endl;
    cout << ans << endl;
  } else {
    ll ans = comb[mp[v[A-1]]][cnt];
    cout << fixed << setprecision(6) << sum/(double)A << endl;
    cout << ans << endl;
  }
  return 0;
}