#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<ctime>
#include<numeric>

using namespace std;
using ll = long long;

ll solve(int n, int r, int k, vector<ll>a, ll acc, ll now, int used){
  if(n == r){
    // cout << used << ' ' << k << ' ' << acc << endl;
    if(used < k) return 1e11+7;
    return acc;
  }
  ll ret = 1e11+7;
  if(now+1 > a[r]){
    ret = solve(n, r+1, k, a, acc, now, used);
  }
  acc += max(ll(0), now+1 - a[r]);
  now = max(now+1, a[r]);
  return min(ret, solve(n, r+1, k, a, acc, now, used+1));
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int ti = clock();
  // start-----------------------------------------------
  int k, n;
  cin >> n >> k;
  vector<ll> a(n);
  for(auto &i : a) cin >> i;

  cout << solve(n, 0, k, a, 0, 0, 0) << endl;

  // end-----------------------------------------------
  cerr << 1.0 * (clock() - ti) / CLOCKS_PER_SEC << endl;
}
