#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

const int N = 1e5 + 5;

ll a[N],ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  for (int i = 0; i < 7; i++) {
    cin >> a[i];
  }
  ans += (a[0] - (a[0] % 2)) + (a[3] - (a[3] % 2)) + (a[4] - (a[4] % 2)) + a[1];
  if (min(a[0],min (a[3],a[4])) > 0) {
    ll k = (a[0] % 2) + (a[3] % 2) + (a[4] % 2);
    if (k == 2)
      ans ++;
    if (k == 3)
      ans += 3;
  }
  cout << ans << endl;
}