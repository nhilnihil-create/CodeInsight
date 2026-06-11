#include <iostream>

using namespace std;

int main()	{
  long long int freq[100001] = {0};
  long long n, k;
  cin >> n >> k;
  long long a, b;
  for (long long i = 0; i < n; i++)	{
    cin >> a >> b;
    freq[a] += b;
  }
  for (long long i = 1; i < 100001; i++)	{
    if (freq[i] >= k)	{
      cout << i << endl;
      break;
    }
    k -= freq[i];
  }
  return 0;
}