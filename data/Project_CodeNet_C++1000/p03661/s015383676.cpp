
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<complex>
#include<sstream>
#include<climits>

#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX_N = 200000;
int N;
ll a[MAX_N];

int main() {
  cin >> N;
  rep(i,N) cin >> a[i];

  ll sum = 0;
  rep(i,N) sum += a[i];

  ll ans = 1e18;
  ll t = 0;
  for (int i = 0; i < N-1; ++i) {
    t += a[i];
    ans = min(ans, abs((sum-t) - t));
  }

  cout << ans << endl;

  return 0;
}
