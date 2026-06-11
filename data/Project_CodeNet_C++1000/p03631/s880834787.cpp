#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  int a = n / 100;
  int b = n % 10;
  if (a == b) cout << "Yes" << endl;
  else cout << "No" << endl;
}
