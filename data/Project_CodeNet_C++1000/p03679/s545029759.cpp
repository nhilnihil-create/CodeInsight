#include <bits/stdc++.h>
using namespace std;
int main() {
  int x,a,b;
  cin >> x >> a >> b;
  int y = a-b;
  if (y >= 0) {
    cout << "delicious" << endl;
  } else if (b-a <= x) {
    cout << "safe" << endl;
  } else {
    cout << "dangerous" << endl;
  }
}