#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n; cin >> n;

  if (n % 10 == 9) {
    cout << "Yes" << "\n";
    return 0;
  }

  n /= 10;
  if (n % 10 == 9) cout << "Yes" << "\n";
  else cout << "No" << "\n";
}
