#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int main()
{
  int N;
  cin >> N;
  vector<int> a(N);
  vector<int> b(N);
  rep(i, N)
  {
    int t;
    cin >> t;
    a[i] = t - 1;
  }

  int ans = 0;
  rep(i, N)
  {
    if (a[a[i]] == i)
    {
      ans++;
    }
  }

  cout << ans / 2 << endl;
  return 0;
}