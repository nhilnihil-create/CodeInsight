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
  int N, C, K;
  cin >> N >> C >> K;
  int ans = 0;
  long long buss_time = 0, buss_count = 0;
  vector<int> T(N);
  rep(i, N)
  {
    cin >> T[i];
  }
  SORT(T);
  rep(i, N)
  {
    if (buss_time < T[i] || buss_count >= C)
    {
      ans++;
      buss_time = T[i] + K;
      buss_count = 1;
    }
    else
      buss_count++;
  }
  cout << ans << endl;
  return 0;
}