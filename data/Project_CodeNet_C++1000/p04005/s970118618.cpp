#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main()
{
  ll a, b, c;
  cin >> a >> b >> c;
  if ((a*b*c)%2==0) {
    cout << "0" << endl;
    exit(0);
  }
  cout << min(a*b, min(b*c, c*a)) << endl;
  return 0;
}