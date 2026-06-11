#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, k, x, y;
  cin >> n;
  cin >> k;
  cin >> x;
  cin >> y;
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += i < k ? x : y;
  }
  cout << sum << endl;
}