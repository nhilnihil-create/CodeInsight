#include <cstdlib>
#include <functional>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <string>

#define ll long long int

using namespace std;

ll factorial(ll x) {
  if (x == 0) {
    return 1;
  }

  ll ret = 1;
  for (ll i = 1; i <= x; i++) {
    ret *= i;
  }
  return ret;
}

int main(int argc, char *argv[])
{
  string s;
  cin >> s;

  for (ll i = 0; i < s.size(); i++) {
    if (s[i] == s[i+1]) {
      cout << i + 1 << " " << i + 2;
      return 0;
    }

    if (s[i] == s[i+2]) {
      cout << i + 1 << " " << i + 3;
      return 0;
    }
  }

  cout << "-1 -1";
}