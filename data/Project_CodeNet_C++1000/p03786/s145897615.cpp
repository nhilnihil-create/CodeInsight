#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, ans = 1;
  cin >> N;
  vector<int64_t> A(N), S(N + 1, 0);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  for (int i = 0; i < N; i++)
  {
    S[i + 1] = S[i] + A[i];
  }
  for (int i = N - 1; i >= 1; i--)
  {
    if (S[i] * 2 >= A.at(i))
      ans++;
    else
      break;
  }
  cout << ans << endl;
}