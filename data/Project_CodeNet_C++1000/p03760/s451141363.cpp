#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool PN(T x)
{
  if (x <= 1)
    return false;
  if (x == 2)
    return true;
  for (int i = 2; i < sqrt(x) + 1; i++)
    if (x % i == 0)
      return false;
  return true;
}

void solve()
{
  string o, e; cin >> o >> e;
  int no, ne;
  no = o.size();
  ne = e.size();
  string ans;
  for(int i =0; i < no; i++){
    ans += o[i];
    if( ne != i) ans+= e[i];
  }
  cout << ans << endl;
}

int main()
{
  solve();
  return 0;
}