#include<bits/stdc++.h>
using namespace std;
int main () {
  int a, b, c;
  cin >> a >> b >> c;
  int m = max(a, max(b, c));
  int s = a + b + c;
  cout << (m * 2 == s ? "Yes" : "No") << endl;
}