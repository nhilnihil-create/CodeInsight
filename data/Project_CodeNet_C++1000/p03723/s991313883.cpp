#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main()
{
  ll a, b, c;
  cin >> a >> b >> c;
  for (int result = 0; result < 1000; ++result) {
    if (a % 2 || b % 2 || c % 2) {
      cout << result << endl;
      return 0;
    }
    ll aa = a / 2;
    ll bb = b / 2;
    ll cc = c / 2;
    a = bb + cc;
    b = aa + cc;
    c = aa + bb;
  }
  cout << - 1 << endl;
  return 0;
}
