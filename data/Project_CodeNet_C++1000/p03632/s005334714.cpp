#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int num = 0;
  
  for (int i = 0; i <= 100; i++) {
  	if (a <= i && i <= b && c <= i && i <= d) num++;
  }
  if (num == 0) num++;
  cout << num - 1 << endl;
}
