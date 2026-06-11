#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, A, B, ans = 0;
  cin >> N >> A >> B;
  vector<int64_t> X(N), D(N, 0);
  for (int i = 0; i < N; i++)
  {
    cin >> X.at(i);
    if (i)
    {
      D.at(i) = A * (X.at(i) - X.at(i - 1));
    }
  }
  for (int i = 1; i < N; i++)
  {
    if (D.at(i) < B)
      ans += D.at(i);
    else
      ans += B;
  }
  cout << ans << endl;
}