#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> D(10);
  int d;
  for (int i = 0; i < K; i++)
  {
    cin >> d;
    D[d] = 1;
  }

  for (int i = N; N <= 10000; i++)
  {
    int c = i;
    while (c && !D[c % 10])
      c /= 10;

    if (c == 0)
    {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}
