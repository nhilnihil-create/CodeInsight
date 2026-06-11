#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int main()
{
  ll A[3];
  cin >> A[0] >> A[1] >> A[2];
  if (A[0] % 2 == 0 || A[1] % 2 == 0 || A[2] % 2 == 0)
  {
    cout << 0 << endl;
  }
  else
  {
    cout << min(A[1] * A[2], min(A[2] * A[0], A[0] * A[1])) << endl;
  }
  return 0;
}