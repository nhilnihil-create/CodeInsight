#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int a, b, c;
  cin >> a >> b >> c;

  for (int i = 1; i <= b; ++i) {
    if (a * i % b == c % b) {
      cout << "YES" << "\n";
      return 0;
    }
  }

  cout << "NO" << "\n";
}
