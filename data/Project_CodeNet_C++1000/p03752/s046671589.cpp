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
  int N, K;
  cin >> N >> K;
  vector<long long> a(N);
  rep(i, N)
  {
    cin >> a[i];
  }

  long long ans = INT64_MAX;

  rep(div, 1 << (N + 1) - 1)
  {
    long long max_height = 0;
    vector<long long> temp = a;
    long long money = 0;
    rep(bit, N)
    {
      if (div >> bit & 1)
      {
        temp[bit] = max(max_height + 1, temp[bit]);
        money += temp[bit] - a[bit];
      }
      max_height = max(max_height, temp[bit]);
    }

    long long count = 0;
    long long min_height = -1;
    rep(i, N)
    {
      if (temp[i] > min_height)
      {
        count++;
        min_height = temp[i];
      }
    }
    if (count >= K)
      ans = min(ans, money);
  }

  cout << ans << endl;
  return 0;
}