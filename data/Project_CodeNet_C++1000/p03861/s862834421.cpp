#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;

typedef long long ll;

ll ceil(ll a, ll x) {
  ll i = a;
  if(i%x != 0) i+=x-i%x;
  return i;
}

ll floor(ll a, ll x) {
  ll i = a;
  if(i%x) i-=i%x;
  return i;
}

int main() {
  long long a,b,x;
  cin >> a >> b >> x;
  long long cnt = 0;
  ll c,out;
  c = floor(b, x) - ceil(a, x);
  if (c < 0) out = 0;
  else out = c / x + 1;
  cout << out << endl;
  return 0;
}
