#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int n;

  cin >> n;

  ll sum = 1;

  ll waru = 1e9 + 7;

  for (int i = 1; i <= n; i++)
  {
    sum *= i % waru;
    sum %= waru;
  }

  cout << sum;
}
