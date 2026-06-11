#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  long power = 1;
  cin >> N;
  long e = pow(10, 9) + 7;

  for(int i = 1; i <= N; i++) {
    power *= i;
    if(power >= e) power %= e;
  }
  cout << power << endl;
}