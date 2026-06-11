#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  cin.tie(0); 

  string s;
  for (int i = 0; i < 3; ++i) {
    string a;
    cin >> a;
    s += toupper(a[0]);
  }
  cout << s << "\n";
}
