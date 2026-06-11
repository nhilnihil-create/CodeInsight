#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  int64_t N = S.size();
  int64_t ans = N * (N - 1) / 2 + 1;
  map<char, int64_t> mp;
  for (int i = 0; i < N; i++)
  {
    mp[S.at(i)]++;
  }
  for (auto it = mp.begin(); it != mp.end(); it++)
  {
    ans -= (it->second) * ((it->second) - 1) / 2;
  }
  cout << ans << endl;
}