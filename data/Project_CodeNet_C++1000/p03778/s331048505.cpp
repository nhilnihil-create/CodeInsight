#include <bits/stdc++.h>
using namespace std;
int main() {
  int W, a, b;
  cin >> W >> a >> b;
  int x = 0;
  if (b - a > W || a - b  > W){
  if (a < b && a + W != b)
    x = b - (a + W);
  else if (a > b && a != b + W)
    x = a - (b + W);
  }
  cout << x << endl;
}