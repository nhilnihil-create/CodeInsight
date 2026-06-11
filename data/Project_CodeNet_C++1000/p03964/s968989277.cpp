#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()	{
  int n;
  cin >> n;
  int t[n], a[n];
  for (int i = 0; i < n; i++)	{
	cin >> t[i];
	cin >> a[i];
  }
  long long A = 1, B = 1;
  long long total = 0;
  for (int i = 0; i < n; i++)	{
	long long x = t[i], y = a[i];
  	long long n = max((A - 1) / x + 1, (B - 1) / y + 1);
    A = n * x;
	B = n * y;
  }
  total = A + B;
  cout << total << endl;
  return 0;
}
