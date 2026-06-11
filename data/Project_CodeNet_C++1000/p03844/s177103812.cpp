#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
  int A,B;
  char x;
  cin >> A >> x >> B;
  cout << (x=='+' ? A+B : A-B);
}