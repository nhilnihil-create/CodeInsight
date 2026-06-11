#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t a, b, c;
  cin >> a >> b >> c;
  
  if ((a % 2) * (b % 2) * (c % 2) == 0 ) {
    cout << 0 << endl;
  }
  else {
    cout << min(min((a * b),(b * c)),(c * a)) << endl;
  }
}
