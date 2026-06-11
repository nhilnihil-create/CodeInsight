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
  int n;
  cin >> n;
  vll a(3 * n);
  for (int i = 0; i < 3 * n; ++i) cin >> a[i];
  sort(a.rbegin(), a.rend());
  ll result = 0;
  for (int i = 0; i < n; ++i) result += a[2 * i + 1];
  cout << result << endl;
  return 0;
}
