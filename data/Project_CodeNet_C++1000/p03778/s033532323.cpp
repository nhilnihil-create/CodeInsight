#include <bits/stdc++.h>
using namespace std;
int main() {
  int W,a,b;
  cin >> W >> a >> b;
  if (b >= a && b <= a+W || b+W >= a && b <= a) {
    cout << 0;
  } else {
    cout << min(abs(b-a),min(abs(b+W-a),abs(b-W-a)));
  }
}