#include <bits/stdc++.h>
#include <iterator>
#include <tuple>
using namespace std;
using ll = long long;

int main()
{
  ll x;
  cin >> x;
  ll sum = 0;
  for (ll i = 1; i < 1e9; ++i)
  {
    sum += i;
    if (x <= sum)
    {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}