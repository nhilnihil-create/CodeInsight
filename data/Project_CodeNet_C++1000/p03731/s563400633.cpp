#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()	{
  long long n, t;
  cin >> n >> t;
  vector<long long int> a;
  for (int i = 0; i < n; i++)	{
    a.push_back(0);
  }
  for (int i = 0; i < n; i++)	{
    cin >> a[i];
  }
  long long total = t;
  for (int i = 0; i < n - 1; i++)	{
    total += min(t, a[i + 1]- a[i]);
  }
  cout << total << endl;
  return 0;
}