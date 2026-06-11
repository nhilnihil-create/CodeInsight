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
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;
const int MOD = 1000000007;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main()
{
  ll a, b, x;
  cin >> a >> b >> x;
  ll ue, shita;
  if (a % x == 0) {
    shita = a / x;
  } else {
    shita = a / x + 1;
  }

  if (b % x == 0) {
    ue = b / x;
  } else {
    ue = b / x;
  }

  cout << ue - shita + 1 << endl;
}
