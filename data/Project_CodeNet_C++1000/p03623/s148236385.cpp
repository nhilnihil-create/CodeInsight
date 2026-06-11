#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int x, a, b;
  cin >> x >> a >> b;
  vector<int> count(2);
  if (x < a) {
    count[0] = a - x;
  }
  else {
    count[0] = x - a;
  }
  if (x < b) {
    count[1] = b - x;
  }
  else {
    count[1] = x - b;
  }
  if (count[0] < count[1]) {
    cout << "A" << endl;
  }
  else {
    cout << "B" << endl;
  }
}