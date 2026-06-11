#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

#include <bits/stdc++.h>

int main() {
  ll n, a, b;
  cin >> n >> a >> b;

  ll num = 0;
  if (a == b) num = 1;
  else if (n >= 2 && a <= b) {
    num = (n - 1) * b + a - ( (n - 1) * a + b) + 1;
  }
  cout << num << endl;

}
