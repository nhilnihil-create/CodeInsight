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
  ll n, a, b;
  cin >> n >> a >> b;
  if (a > b || n == 1 && a != b) {
    cout << 0 << endl;
    return 0;
  }
  if (a == b) n--; else n -= 2;
  ll k = b - a + 1;
  cout << n * k - n + 1 << endl;
  return 0;
}
