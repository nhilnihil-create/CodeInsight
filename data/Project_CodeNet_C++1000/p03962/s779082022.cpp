#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int count = 0;
  if (a==b || a==c || b==c) {
    count++;
  }
  if (a==b && a==c && b==c) {
    count++;
  }
  cout << 3 - count << endl;
}