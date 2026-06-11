#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int a, b;
  cin >> a >> b;

  if ((a + b) % 3 == 0 || a % 3 == 0 || b % 3 == 0)
    cout << "Possible";
  else
  {
    cout << "Impossible";
  }
}
