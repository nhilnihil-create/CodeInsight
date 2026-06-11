#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, l, r, ans = 0;
  cin >> N;
  vector<int64_t> S(100010, 0);
  for (int i = 0; i < N; i++)
  {
    cin >> l >> r;
    S[l]++;
    S[r + 1]--;
  }
  for (int i = 1; i < 100010; i++)
  {
    S[i] += S[i - 1];
    if (S[i])
      ans++;
  }
  cout << ans << endl;
}