#include <bits/stdc++.h>

using namespace std;

const int N = 100000 + 3;

typedef long long ll;

void no() {
  puts("NO");
  exit(0);
}

void yes() {
  puts("YES");
  exit(0);
}

int main() {
  ll n;
  scanf("%lld", &n);

  vector<ll> a(n, 0);
  ll sum = 0;
  for(int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
    sum += a[i];
  }

  ll once = (n * (n + 1)) / 2;

  if(sum % once) no();

  ll k = sum / once;

  for(int i = 0; i < n; ++i) {
    ll d = a[i] - a[(i + n - 1) % n];
    //only 2 possible cases:
    //d == k or d == -x(n - 1) + (k - x) == -nx + k
    if((k - d < 0) || (k - d) % n > 0) no();
  }

  yes();
  return 0;
}
