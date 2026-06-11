#include <math.h>
#include <stdio.h>
#include <bitset>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  long int N;
  cin >> N;
  int minVal = -1;
  for (long int a = 1; a <= pow(10, 5); a++) {
    if (N % a == 0) {
      long int b = N / a;
      int m = max((int)to_string(a).size(), (int)to_string(b).size());
      if (minVal < 0) {
        minVal = m;
      } else {
        minVal = min(minVal, m);
      }
    }
  }
  cout << minVal << endl;
}