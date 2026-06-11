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

int main()
{
  ll a, b, c, d, n;
  cin >> a >> b >> c >> d >> n;
  n *= 4;
  b = min(b, 2 * a);
  c = min(c, 2 * b);
  d = min(d, 2 * c);
  ll result = 0;
  result += n / 8  * d;
  n %= 8;
  result += n / 4 * c;
  n %= 4;
  result += n / 2 * b;
  n %= 2;
  result += n * a;
  cout << result << endl;
  return 0;
}
