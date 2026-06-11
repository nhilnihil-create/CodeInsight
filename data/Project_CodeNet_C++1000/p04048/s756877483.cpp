#include <bits/stdc++.h>
using namespace std;

long long ans;

void calc(long long a, long long b) {
	if (a % b == 0) {
      ans += (a * 2) - b;
      return;
    }
  ans += (a / b) * b * 2;
  calc(b, a % b);
}

int main() {
  long long n, x;
  cin >> n >> x;
  ans = n;
  if (x < n - x)
    x = n - x;
  calc(x, n - x);
  	cout << ans;
 	return 0; 
}
