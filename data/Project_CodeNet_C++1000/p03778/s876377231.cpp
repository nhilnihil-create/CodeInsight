#include <bits/stdc++.h>
using namespace std;
using pp=pair<int, int>;

int main() {
  long long W, a, b;
  cin >> W >> a >> b;
  if (((b+W)-a)*(b-(a+W))<=0) {
    cout << 0 << endl;
  }
  else {
    cout << min(abs(b-(a+W)), abs(b+W-a));
  }
}
