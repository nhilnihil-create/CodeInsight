#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, ans = 0;
  cin >> n;

  for (int i = 0; i < 100; i++)
  {
    if (n >= pow(2, i))
    {
      ans = max(ans, (int)pow(2, i));
    }
  }
  cout << ans << endl;
}
