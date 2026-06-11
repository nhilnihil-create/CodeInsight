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
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;
const int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<ll> t(n), a(n);

  rep(i, n) {
    cin >> t[i] >> a[i];
  }

  ll num = 1;
  ll T = t[0];
  ll A = a[0];
  for(int i = 1; i < n; ++i) {
    num = max((T + t[i] - 1) / t[i], (A + a[i] - 1) / a[i]);
    T = t[i] * num;
    A = a[i] * num;
  }
  cout << num * a[n - 1] + num * t[n - 1]  << endl;
}