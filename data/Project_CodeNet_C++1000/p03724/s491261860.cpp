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
  vector<int> node(N);
  rep(i, M)
  {
    int a, b;
    cin >> a >> b;
    node[a - 1]++;
    node[b - 1]++;
  }
  for (int count : node)
  {
    if (count % 2 == 1)
    {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  return 0;
}