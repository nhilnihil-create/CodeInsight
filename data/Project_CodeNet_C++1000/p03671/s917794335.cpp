#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  vector<int> a(3);
  rep(i, 3) cin >> a.at(i);
  sort(a.begin(), a.end());

  // rep(i, 3) cout << a.at(i);

  cout << a.at(0) + a.at(1);

  // cout << tmp;
}
