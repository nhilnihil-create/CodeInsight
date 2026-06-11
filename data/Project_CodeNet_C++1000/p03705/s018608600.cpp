#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int main() {
  int64_t N, A, B;
  cin >> N >> A >> B;
  if (A>B) {
    cout << 0 << endl;
  }
  else {
    if (N!=1) {
      cout << (B-A)*(N-2)+1 << endl;
    }
    else {
      if (A!=B) {
        cout << 0 << endl;
      }
      else {
        cout << 1 << endl;
      }
    }
  }
}