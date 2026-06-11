#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()	{
  int n, k;
  cin >> n >> k;
  int x[n];
  for (int i = 0; i < n; i++)	{
    cin >> x[i];
  }
  int res = 0;
  for (int i = 0; i < n; i++)	{
    res += min(2 * abs(x[i]), 2 * abs(x[i] - k));
  }
  cout << res << endl;
  return 0;
}