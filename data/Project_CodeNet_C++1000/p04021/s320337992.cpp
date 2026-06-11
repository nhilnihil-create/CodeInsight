#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, ans;
  cin >> N;
  vector<int64_t> A(N);
  map<int64_t, int64_t> mp;
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
    mp[A.at(i)] = i;
  }
  sort(A.begin(), A.end());
  for (int i = 0; i < N; i++)
  {
    int64_t d = abs(mp[A.at(i)] - i);
    if (d % 2)
    {
      ans++;
    }
  }
  cout << ans / 2 << endl;
}