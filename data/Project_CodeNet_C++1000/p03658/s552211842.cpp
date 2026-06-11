#include <iostream>
#include <algorithm>

using namespace std;

int main()	{
  long long n, k;
  cin >> n >> k;
  long long a[n];
  for (int i = 0; i < n; i++)	{
    cin >> a[i];
  }
  sort(a, a + n, greater<int>());
  long long length = 0;
  for (int i = 0; i < k; i++)	{
    length += a[i];
  }
  cout << length << endl;
  return 0;
}