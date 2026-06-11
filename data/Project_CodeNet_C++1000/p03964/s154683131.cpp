#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std; //std::の省略のため
using ll = long long;

int main()
{
  int n;
  cin >> n;

  ll t[n], a[n];
  for (int i = 0; i < n; i++)
    cin >> t[i] >> a[i];

  ll now_t = t[0], now_a = a[0];
  //cout << now_t << " : " << now_a << endl;

  ll k;

  for (int i = 1; i < n; i++)
  {
    k = max((now_t - 1)/ t[i] + 1, (now_a - 1) / a[i] + 1);

    now_t = t[i] * k;
    now_a = a[i] * k;

    //cout << now_t << " : " << now_a << endl;
  }

  ll ans = now_a + now_t;

  cout << ans << endl;
}
