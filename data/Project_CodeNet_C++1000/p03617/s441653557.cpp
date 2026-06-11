#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
using namespace std;
typedef long long ll;
int main(){
  int q,h,s,d;
  ll n = 0;
  cin >> q >> h >> s >> d >> n;
  int l2 = 0;
  int l1 = 0;
  l2 = min(d,s * 2);
  l2 = min(l2,h * 4);
  l2 = min(l2,q * 8);
  l1 = min(s,2 * h);
  l1 = min(l1,4 * q);
  ll res = 0;
  if(n % 2 == 0)res = n / 2 * l2;
  else res = n / 2 * l2 + l1;
  cout << res << endl;
  return 0;
}