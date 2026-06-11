#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, ans = 0;
  cin >> N;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  for (int i = 0; i < N - 1; i++)
  {
    ans += A[i] / 2;
    if (A[i] % 2 && A[i + 1] >= 1)
    {
      ans++;
      A[i + 1]--;
    }
  }
  ans += A[N - 1] / 2;
  cout << ans << endl;
}