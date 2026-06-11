#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  int a[N];
  for (int i = 0; i < N; i++)
  {
    cin >> a[i];
  }
  int min_sum = 2147483647;
  for (int i = -100; i <= 100; i++)
  {
    int sum = 0;
    for (int j = 0; j < N; j++)
    {
      sum += pow(abs(a[j] - i), 2);
    }
    if (sum < min_sum)
    {
      min_sum = sum;
    }
  }
  cout << min_sum << endl;
  return 0;
}