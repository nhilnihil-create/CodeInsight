#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  int a = n / 10;
  int b = n % 10;
  if (a == 9 || b == 9) cout << "Yes" << endl;
  else cout << "No" << endl;
}
