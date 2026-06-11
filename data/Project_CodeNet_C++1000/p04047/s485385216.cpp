#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, ans = 0;
  cin >> N;
  vector<int64_t> A(2 * N);
  for (int i = 0; i < 2 * N; i++)
  {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  for (int i = 0; i < 2 * N; i += 2)
  {
    ans += A.at(i);
  }
  cout << ans << endl;
}