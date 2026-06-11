#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std; //std::の省略のため
using ll = long long;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;

  int count = 0;

  if (b == a)
    count++;

  if (c == b || c == a)
    count++;

  int ans = 3 - count;
  cout << ans << endl;
}
