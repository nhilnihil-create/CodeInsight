#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int main()
{
  int N, count = 0;
  string s, t, c, d;
  cin >> N >> s >> t;
  for (int i = 0; i < N; i++)
  {
    c = s.substr(i, N);
    d = t.substr(0, N - i);
    if (c == d)
    {
      count = c.size();
      break;
    }
  }
  cout << 2 * N - count << endl;
  return 0;
}