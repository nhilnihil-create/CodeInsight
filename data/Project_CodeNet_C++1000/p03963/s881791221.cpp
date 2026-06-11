#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  long long sum = 0;

  sum = k * pow(k - 1, n - 1);

  cout << sum << endl;
}
