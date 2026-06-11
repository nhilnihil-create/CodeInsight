#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, a, ans = 0;
  cin >> N;
  map<pair<int, int>, bool> mp;
  for (int i = 1; i <= N; i++)
  {
    cin >> a;
    mp[make_pair(i, a)] = 1;
    if (mp.count(make_pair(a, i)))
      ans++;
  }
  cout << ans << endl;
}
