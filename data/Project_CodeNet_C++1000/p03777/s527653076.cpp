#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) { // n が 0 になるまで
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int main(){
  char a,b;
  cin >> a >> b;
  if(a == 'H' && b == 'H') cout << "H" << endl;
  else if(a == 'H' && b == 'D') cout << "D" << endl;
  else if(a == 'D' && b == 'H') cout << "D" << endl;
  else cout << "H" << endl;

}