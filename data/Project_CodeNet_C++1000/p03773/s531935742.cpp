#include<bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int t = a+b;
  while (t >= 24) {
    t -= 24;
  }
  cout << t << endl;
  return 0;
}