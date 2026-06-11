#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;
const int INF = 1001001001;

vector<P> factor(int n) {
  vector<P> res;
  for (int i = 2; i * i <= n; ++i) {
    if(n % i) continue;
    res.emplace_back(i, 0);
    while(n % i == 0) {
      res.back().second++;
      n /= i;
    }
  }
  if(n != 1) res.emplace_back(n, 1);
  return res;

}

int main() {
  int n;
  cin >> n;
  vector<int> cnt(n + 1);

  for(int i = 1; i <= n; ++i) {
    auto f = factor(i);
    for (P p : f) {
      cnt[p.first] += p.second;
    }
  }
  ll ans = 1;
  for(int i = 1; i <= n; ++i) {
    ans *= cnt[i] + 1;
    ans %= mod;
  }
  cout << ans << endl;

}
