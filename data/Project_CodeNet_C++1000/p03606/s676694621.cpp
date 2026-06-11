#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, L, R;
  cin >> N;
  int sum = 0;
  for (int i = 0; i < N + 1; i++)
  {
    if (i == N)
    {
      cout << sum << endl;
      break;
    }
    cin >> L >> R;
    if (L > R)
    {
      sum += (L - R + 1);
    }
    else if (R > L)
    {
      sum += (R - L + 1);
    }
    else
    {
      sum += 1;
    }
  }
}
