#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std; //std::の省略のため
using ll = long long;

int main()
{

  int n, k, x, y;
  cin >> n >> k >> x >> y;

  int ans;

  if (n < k)
    ans = n * x;
  else
    ans = k * x + (n - k) * y;

  cout << ans << endl;
}
