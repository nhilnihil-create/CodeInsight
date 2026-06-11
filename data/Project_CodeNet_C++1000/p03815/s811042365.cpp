#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll x, count;
  count = 0;
  cin >> x;

  count += x / 11;
  count *= 2;
  int a = x % 11;
  if (a > 0 && a <= 6)
  {
    count++;
  }
  else if (a > 6)
  {
    count += 2;
  }

  cout << count << endl;
}
