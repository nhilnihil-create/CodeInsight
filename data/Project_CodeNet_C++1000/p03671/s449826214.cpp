#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int a = 10000, b = 10000;

  for (int i = 0; i < 3; ++i) {
    int x; cin >> x;

    if (x < a) {
      b = a, a = x;
    } else if (x < b) b = x;
  }

  cout << a + b << "\n";
}
