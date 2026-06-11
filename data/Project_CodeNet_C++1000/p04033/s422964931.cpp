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
  int a, b;
  cin >> a >> b;
  if (a > 0)
  {
    cout << "Positive" << endl;
  }
  else if (a <= 0 && b >= 0)
  {
    cout << "Zero" << endl;
  }
  else
  {
    int count = (-a) - (-b);
    if (count % 2 == 0)
      cout << "Negative" << endl;
    else
      cout << "Positive" << endl;
  }
  return 0;
}