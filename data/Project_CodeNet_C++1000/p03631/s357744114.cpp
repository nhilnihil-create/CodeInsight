#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin >> a;
  int b = a/100;
  int c = (a%100)/10;
  int d = (a%100)%10;
  if (b == d) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}