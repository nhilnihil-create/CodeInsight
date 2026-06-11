#include <iostream>

using namespace std;

int main()	{
  int n, k;
  cin >> n >> k;
  if (n == 1)	{
    cout << k << endl;
    return 0;
  }
  int ways = 0;
  ways = k;
  for (int i = 0; i < n - 1; i++)	{
    ways *= (k - 1);
  }
  cout << ways << endl;
  return 0;
}