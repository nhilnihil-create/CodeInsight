#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, i, x;
  cin >> n;
  x=0;
  for(i=0;i<n;i++) {
    cin >> a >> b;
    x += b-a+1;
  }
  cout << x << endl;
  return 0;
}
  