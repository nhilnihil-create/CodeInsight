#include <bits/stdc++.h>
typedef long long LL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;

LL gcd(LL a, LL b) { return a&&b?gcd(b,a%b):a+b; }

int main(void)
{
  LL n, x;
  cin >> n >> x;
  cout << (n-gcd(n,x))*3 << endl;
  return 0;
}
