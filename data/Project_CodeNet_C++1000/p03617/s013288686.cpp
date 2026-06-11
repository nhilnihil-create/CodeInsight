#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t p, N, n, ans = 0;
  vector<pair<int64_t, int64_t>> vp;
  for (int i = 3; i >= 0; i--)
  {
    cin >> p;
    int64_t x = pow(2, i);
    vp.push_back(make_pair(x * p, 8 / x));
  }
  cin >> N;
  sort(vp.begin(), vp.end());
  n = 4 * N;
  for (int i = 0; i < 4; i++)
  {
    int64_t l = vp.at(i).second;
    int64_t c = vp.at(i).first / (8 / l);
    ans += c * (n / l);
    n %= l;
  }
  cout << ans << endl;
}