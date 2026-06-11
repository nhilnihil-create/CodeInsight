#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int a, b, c;
  cin >> a >> b >> c;

  if (c <= b) cout << "delicious" << "\n";
  else if (c <= b + a) cout << "safe "<< "\n";
  else cout << "dangerous" << "\n";
}
