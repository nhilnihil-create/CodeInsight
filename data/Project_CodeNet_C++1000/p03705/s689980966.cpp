#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int main()
{
  ll N, A, B;
  cin >> N >> A >> B;
  if (A > B)
  {
    cout << 0 << endl;
  }
  else if (N == 1)
  {
    if (A != B)
    {
      cout << 0 << endl;
    }
    else
    {
      cout << 1 << endl;
    }
  }
  else
  {
    cout << (B - A) * (N - 2) + 1 << endl;
  }
  return 0;
}