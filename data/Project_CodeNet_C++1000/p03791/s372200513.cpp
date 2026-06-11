#include <bits/stdc++.h>
typedef long long LL;
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;
LL p = 1000000007ll;

int main(void)
{
  LL n;
  cin >> n;
  vector<LL> a(n);
  for(LL &x:a) cin >> x;
  LL answer = 1;
  LL tmp = 1;
  REP(i,n-1) {
    if((a[i]+3)/2 > tmp) ++tmp;
    answer *= tmp;
    answer %= p;
  }
  cout << answer << endl;
  return 0;
}
