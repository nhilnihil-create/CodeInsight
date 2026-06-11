#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int countDigit(ll num) {
  int count = 0;

  while (num > 0) {
    num /= 10;
    count++;
  }
  return count;
}

bool isPrime(ll num) {
  if (num < 2) return false;
  else if (num == 2) return true;
  else if (num % 2 == 0) return false;

  double sqrtNum = sqrt(num);
  for (int i = 3; i <= sqrtNum; i += 2) {
    if (num % i == 0) {
      return false;
    }
  }

  return true;
}

int main(void) {
  ll n;
  cin >> n;

  int ans = 10;
  double r = sqrt((double)n);
  if ((ll)r * r == n) {
    ans = countDigit((ll)r);
  } else if (isPrime(n)) {
    ans = countDigit(n);
  } else {
    for (ll i = (ll)r - 1; i <= n; ++i) {
      if (n % i == 0) {
        ans = countDigit(i);
        break;
      }
    }
  }

  cout << ans << endl;
  
  return 0;
}