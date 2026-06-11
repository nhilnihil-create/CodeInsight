#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t K, S, ans = 0;
  cin >> K >> S;
  for (int i = 0; i <= K; i++)
  {
    for (int j = 0; j <= K; j++)
    {
      if (i + j <= S && S - i - j <= K)
        ans++;
    }
  }
  cout << ans << endl;
}