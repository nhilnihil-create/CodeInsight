#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

int rec(int n, int i) {
  if(i <= n * (n + 1) / 2) {
    return n;
  }
  return rec(n + 1, i);
}

int main(void) {
  int x;
  cin >> x;

  cout << rec(1, x) << endl; 
}