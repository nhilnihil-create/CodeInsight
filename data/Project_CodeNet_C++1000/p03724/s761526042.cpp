#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;

bool compare(pair<int, int> a, pair<int, int> b)
{
  return a.second < b.second;
}

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> cnt;
  cnt.resize(N);
  for (int i = 0; i < M; ++i)
  {
    int a, b;
    cin >> a >> b;
    --a, --b;
    ++cnt[a], ++cnt[b];
  }
  for (int i = 0; i < N; ++i)
  {
    if (cnt[i] % 2 == 1)
    {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
