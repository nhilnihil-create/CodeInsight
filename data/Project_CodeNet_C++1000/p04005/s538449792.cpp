#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;

int main()
{
  vector<ll> a(3);
  rep(i, 3) cin >> a[i];

  if (a[0]%2==0 || a[1]%2==0 || a[2]%2==0) {
    cout << 0 << endl;
    return 0;
  }

  sort(a.rbegin(),a.rend());
  cout << a[1]*a[2] << endl;

  return 0;
}
