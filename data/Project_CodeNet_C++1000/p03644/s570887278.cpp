#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;

  int maxval = 1;
  int maxnum = 0;
  for (int i = 1; i <= n; ++i) {
    int tmp = i;
    int num = 0;
    while (tmp % 2 == 0) {
      tmp = tmp / 2;
      ++num;
    }
    
    if (num > maxnum) {
      maxnum = num;
      maxval = i;
    }
  }

  cout << maxval << endl;
  return 0;
}