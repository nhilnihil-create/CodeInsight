#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

template <typename T>
void printlnVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << endl;
  }
}

template <typename T>
void printVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> balls(N, 1);
  balls[0] = -1;
  rep(i, M)
  {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (balls[x] > 0 && balls[y] >= 0)
    {
      balls[x]--;
      balls[y]++;
    }
    else if (balls[x] < 0 && balls[y] >= 0)
    {
      balls[x] = -(-balls[x] - 1);
      balls[y]++;
      balls[y] *= -1;
    }
    else if (balls[x] > 0 && balls[y] <= 0)
    {
      balls[x]--;
      balls[y] = -(-balls[y] + 1);
    }
    else if (balls[x] < 0 && balls[y] <= 0)
    {
      balls[x] = -(-balls[x] - 1);
      balls[y] = -(-balls[y] + 1);
    }
  }
  int ans = 0;
  rep(i, N)
  {
    if (balls[i] < 0)
      ans++;
  }
  cout << ans << endl;
  return 0;
}