#include <iostream>
#include <algorithm>

using namespace std;

int main()	{
  long long n;
  cin >> n;
  long long a[n] = {0};
  long long max = 0;
  long long sum = 0;
  long long smallest_not_divisible = 1000000;
  long long number_not_divisible = 0;
  for (long long i = 0; i < n; i++)	{
    cin >> a[i];
    sum += a[i];
    if (a[i] % 10)	{
      number_not_divisible++;
      if (smallest_not_divisible > a[i])	{
        smallest_not_divisible = a[i];
      }
    }
  }
  if (sum % 10)	{
    cout << sum << endl;
    return 0;
  }
  if (number_not_divisible == 0)	{
    cout << 0 << endl;
  }
  else if (number_not_divisible == 1)	{
    cout << sum << endl;
  }
  else	{
    cout << sum - smallest_not_divisible << endl;
  }
  return 0;
}