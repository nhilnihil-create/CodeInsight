#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int x, a, b;
  cin >> x >> a >> b;

  if (abs(x - a) < abs(x - b)) cout << "A" << "\n";
  else cout << "B" << "\n";
}
