#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main()
{
  int n;
  cin >> n;

  vector<int> a;
  int sum = 0;
  for (int i = 1; i <= n; ++i)
  {
    if (sum >= n)
      break;
    sum += i;
    a.push_back(i);
  }
  for (int i = 0; i < a.size(); ++i)
  {
    if (sum - n == a[i])
      continue;
    cout << a[i] << endl;
  }

  return 0;
}