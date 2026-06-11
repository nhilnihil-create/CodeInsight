#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int a, b;
  cin >> a >> b;

  if (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0) cout << "Possible" << "\n";
  else cout << "Impossible" << "\n";
}
