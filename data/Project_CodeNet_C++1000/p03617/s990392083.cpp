#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

int main() { 
  ll q, h, s, d, n;
  cin >> q >> h >> s >> d >> n;
  ll one = min({q*4, h*2, s});
  cout << min(one*n, d*(n/2)+one*(n%2)) << endl;
}
