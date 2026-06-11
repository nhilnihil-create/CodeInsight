#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
#include<queue>
#include<numeric>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;
const int MOD = 1000000007;

#define rep(i,n) for (int i = 0; i < (n); ++i)

ll comb(ll i, ll j)
{
  if (i < j) {
    ll tmp = j;
    j = i;
    i = tmp;
  }

  if (j > i - j) {
    j = i-j;
  }
  if (j == 0) return 1;

  ll bunsi = 1; ll bunbo = 1;
  for (int k = j; k > 0; k--) {
    bunbo *= k;
  }
  ll tmp = i;
  for (int l = j; l > 0; l--) {
    bunsi *= tmp--;
  }
  return bunsi / bunbo;
}

int main()
{
  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  int oddNum = 0;
  int evenNum = 0;

  rep(i, n) {
    if (a[i] & 1) oddNum++;
    else evenNum++;
  }

  ll zentori = pow(2, n);
  ll kitori = 0;
  // 奇数を奇数こいれることを考える
  for (int i = 0; i <= oddNum; i++) {
    if (!(i & 1)) continue;
    kitori += comb(oddNum, i) * pow(2, evenNum);
    // oddNum C i を pow(2, oddNum) にかけてkitoriに加算
  }

  if (p) {
    cout << kitori << endl;
  } else {
    cout << zentori - kitori << endl;
  }
}


