#include <bits/stdc++.h>
using namespace std;

int main() {
  char a,b;
  int result = 1;
  cin >> a >> b;

  if (a == 'D') {
    result *= -1;
  }
  if (b == 'D') {
    result *= -1;
  }
  if (result == 1) {
    cout << 'H' <<endl;
  } else {
    cout << 'D' <<endl;
  }
}