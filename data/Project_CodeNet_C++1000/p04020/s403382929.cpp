#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  int64_t ans = 0;
  ans += A.at(0) / 2;
  A.at(0) %= 2;
  for (int i = 1; i < N; i++)
  {
    if (A.at(i - 1) && A.at(i) > 0)
    {
      ans++;
      A.at(i)--;
    }
    ans += A.at(i) / 2;
    A.at(i) %= 2;
  }
  cout << ans << endl;
}