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
  long long A, B, C;
  cin >> A >> B >> C;
  long long preA = A, preB = B, preC = C;
  long long ans = 0;
  while (A % 2 == 0 && B % 2 == 0 && C % 2 == 0)
  {
    ans++;
    A = (preB + preC) / 2;
    B = (preC + preA) / 2;
    C = (preA + preB) / 2;
    if (preA == A && preB == B && preC == C)
    {
      ans = -1;
      break;
    }

    preA = A;
    preB = B;
    preC = C;
  }
  cout << ans << endl;
  return 0;
}