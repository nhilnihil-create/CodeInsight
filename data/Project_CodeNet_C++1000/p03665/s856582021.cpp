#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;

int main()
{
  int n, p; cin >> n >> p;
  vector<int> a(n);
  int odd = 0;
  rep(i, n) {
    cin >> a[i];
    if (a[i]%2 == 1) odd++;
  }
  if (odd == 0) {
    if (p == 0) cout << (ll)pow(2, n) << endl;
    else cout << 0 << endl;
  } else cout << (ll)pow(2, n-1) << endl;

  return 0;
}
