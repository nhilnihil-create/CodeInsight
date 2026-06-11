#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int x, i=0, cnt=0;
  cin >> x;
  while (cnt < x) {
    i++;
    cnt += i;
  }
  cout << i << endl;
}