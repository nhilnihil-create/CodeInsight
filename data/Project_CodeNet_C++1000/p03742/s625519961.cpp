#include <bits/stdc++.h>
typedef long long LL;
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;

int main(void)
{
  LL x,y;
  cin >> x >> y;
  cout << (abs(x-y)<2?"Brown":"Alice") << endl;
}
