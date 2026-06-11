#include <bits/stdc++.h>
using namespace std;

int main() {
  int W,a,b;
  cin >> W >> a >> b;
  if (a<=b && b<=a+W) cout << 0 << endl;
  else if (a<=b+W && b+W<=a+W) cout << 0 << endl;
  else cout << max(b-a-W,a-b-W) << endl;
}