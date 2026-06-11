#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int main()
{
  int N;
  cin >> N;
  vector<int> s(N);
  int sum = 0;
  rep(i, N)
  {
    cin >> s[i];
    sum += s[i];
  }

  if (sum % 10 != 0)
  {
    cout << sum << endl;
    return 0;
  }
  else
  {
    sort(s.begin(), s.end());
    for (int i = 0; i < N; i++)
    {
      if (s.at(i) % 10 != 0)
      {
        sum -= s.at(i);
        cout << sum << endl;
        return 0;
      }
    }
    cout << 0 << endl;
  }
  return 0;
}
