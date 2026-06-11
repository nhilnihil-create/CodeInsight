#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, a;
  cin >> N;
  map<int64_t, int64_t> mp;
  for (int i = 0; i < N; i++)
  {
    cin >> a;
    if (mp.count(a))
      mp.erase(a);
    else
      mp[a]++;
  }
  cout << mp.size() << endl;
}