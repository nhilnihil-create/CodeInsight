#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int digits[10] = {0};


bool is_valid(int x) {
  while (x) {
    int d = x % 10;
    if (digits[d]) return false;
    else x /= 10;
  }

  return true;
}

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < k; ++i) {
    int x; cin >> x;
    digits[x] = 1;
  }

  int max_int = ~(1 << 31);

  int res = -1;
  do {
    if (is_valid(n)) res = n;
  } while (n++ < max_int && res == -1);

  cout << res << '\n';
}
