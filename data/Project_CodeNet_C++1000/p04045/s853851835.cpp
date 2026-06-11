#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  unordered_set<int> D(K);
  int d;
  for (int i = 0; i < K; i++)
  {
    cin >> d;
    D.insert(d);
  }

  int n = N++;
  int r = 0;
  while (n)
  {
    r += D.count(n % 10);
    n /= 10;
  }
  while (r)
  {
    n = N++;
    r = 0;
    while (n)
    {
      r += D.count(n % 10);
      n /= 10;
    }
  }

  cout << N - 1 << endl;

  return 0;
}