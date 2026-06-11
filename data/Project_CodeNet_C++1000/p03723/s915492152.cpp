#include<bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if(a % 2 ==0 && a == b && b ==c) {
    cout << -1 << endl;
  } else {
    int count = 0;
    while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
      int copy_a = a;
      int copy_b = b;
      int copy_c = c;
      a = copy_b / 2 + copy_c / 2;
      b = copy_a / 2 + copy_c / 2;
      c = copy_a / 2 + copy_b / 2;
      count++;
    }
    cout << count << endl;
  }
}