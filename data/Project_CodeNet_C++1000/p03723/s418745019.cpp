#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int A, B, C;
  cin >> A >> B >> C;
  for (int i = 0; i < 31; i++){
    if(A % 2 == 1 || B % 2 == 1 || C % 2 == 1){
      cout << i << endl;
      return 0;
    }
    int a = B / 2 + C / 2;
    int b = A / 2 + C / 2;
    int c = A / 2 + B / 2;
    A = a;
    B = b;
    C = c;
  }
  cout << -1 << endl;
}