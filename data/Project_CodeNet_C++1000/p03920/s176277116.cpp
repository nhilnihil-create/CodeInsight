#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int sum_p = 0;
  int i = 1;
  while (true) {
    sum_p += i;
    if (sum_p >= n) {
      break;
    }
    ++i;
  }
  for (int j=1; j<=i; j++) {
    if (j == sum_p - n) {
      continue;
    }
    cout<<j<<endl;
  }

}