#include <bits/stdc++.h>
using namespace std;

int main() {
  int W,a,b;
  cin >> W >> a >> b;
  cout << max(0,(max(a,b)-min(a,b)-W)) << endl;
}
