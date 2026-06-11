#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

template <typename T>
void printlnVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << endl;
  }
}

template <typename T>
void printVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  int x, y;
  cin >> x >> y;

  int ans = INT32_MAX;
  if (x - y <= 0)
    ans = min(ans, -(x - y));
  if (x + y >= 0)
    ans = min(ans, x + y + 1);
  if (x + y <= 0)
    ans = min(ans, -(x + y) + 1);
  if (x - y >= 0)
    ans = min(ans, x - y + 2);

  cout << ans << endl;
  return 0;
}