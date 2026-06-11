#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int N;
  cin >> N;
  int odd = 0;
  rep(i, N) {
    int A;
    cin >> A;
    if (A % 2) ++odd;
  }
  if (odd % 2)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}