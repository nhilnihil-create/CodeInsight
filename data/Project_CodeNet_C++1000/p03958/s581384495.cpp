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
  int K, T;
  cin >> K >> T;
  vector<int> cake, a(T);
  rep(i, T)
  {
    cin >> a[i];
  }
  RSORT(a);
  rep(i, T)
  {
    rep(j, a[i])
    {
      cake.push_back(i);
    }
  }
  vector<int> sort_cake(K);
  rep(i, K)
  {
    if(i * 2 < K)
      sort_cake[i * 2] = cake[i];
    else
    {
      int j = (i * 2) % K;
      //cout <<  j << "->" << j * 2 + 1 << endl;
      //j = j * 2 + 1;
      sort_cake[j] = cake[i];
    }
  }
  int ans = 0;
  rep(i, K - 1)
  {
    if(sort_cake[i] == sort_cake[i + 1])
      ans++;
  }
  cout << ans << endl;
  return 0;
}