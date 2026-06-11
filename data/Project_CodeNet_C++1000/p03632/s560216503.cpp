#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  
  int time = 0;
  if (max(a, c) <= min(b, d)) time = min(b, d) - max(a, c);
  
  cout << time << endl;  // max(0, min(b,d)-max(a,c))でも良い
}