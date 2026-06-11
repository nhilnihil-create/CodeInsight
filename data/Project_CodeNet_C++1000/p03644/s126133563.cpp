#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  if (N<2) {
    cout << 1 << endl;
  }
  else {
    if (N<4) {
      cout << 2 << endl;
    }
    else {
      if (N<8) {
        cout << 4 << endl;
      }
      else {
        if (N<16) {
          cout << 8 << endl;
        }
        else {
          if (N<32) {
            cout << 16 << endl;
          }
          else {
            if (N<64) {
              cout << 32 << endl;
            }
            else {
              cout << 64 << endl;
            }
          }
        }
      }
    }
  }
}