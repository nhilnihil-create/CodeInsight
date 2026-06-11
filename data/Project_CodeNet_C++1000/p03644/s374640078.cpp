#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n;
  cin >> n;
  vector<int> sq(8);
  int tmp = 1;
  rep(i, 8)
  {
    sq[i] = tmp;
    tmp *= 2;
  }
  rep(i, 8)
  {
    if (n < sq[i])
    {
      cout << sq[i - 1] << endl;
      return 0;
    }
  }
  return 0;
}