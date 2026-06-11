#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll a[100010];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % ((1 + n) * n / 2) != 0) {
    cout << "NO\n";
    return 0;
  }
  ll round = sum / ((1 + n) * n / 2);
  sum = 0;
  for (int i = 0; i < n; i++) {
    if (a[(i+1)%n] - a[i] > round || (round - a[(i+1) % n] + a[i]) % n != 0) {
      cout << "NO\n";
      return 0;
    }
    sum += (round - a[(i + 1)%n] + a[i]) / n;
  }
  cout << (sum == round? "YES" : "NO") << endl;
  return 0;
}
