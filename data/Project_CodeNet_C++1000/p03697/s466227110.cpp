#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int a, b;
  cin >> a >> b;

  if (a + b >= 10) cout << "error" << "\n";
  else cout << a + b << "\n";
}
