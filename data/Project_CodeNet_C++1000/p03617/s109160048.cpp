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
  long long Q, H, S, D, N;
  cin >> Q >> H >> S >> D >> N;
  H = min(H, 2 * Q);
  S = min(S, 2 * H);
  D = min(D, 2 * S);
  long long ans = (N / 2) * D;
  if (N % 2 == 1)
    ans += S;
  cout << ans << endl;
  return 0;
}