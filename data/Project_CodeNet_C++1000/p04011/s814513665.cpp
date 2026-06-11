#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  int N, K, X, Y;
  cin >> N >> K >> X >> Y;

  int result = 0;
  if (N < K)
  {
    result += N * X;
  }
  else
  {
    result += K * X + (N - K) * Y;
  }

  cout << result << endl;

  return 0;
}