#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (c <= b) {
    cout << "delicious" << endl;
  }
  if (c > b && c <= a+b) {
    cout << "safe" << endl;
  }
  if (c > a+b) {
    cout << "dangerous" << endl;
  }
}