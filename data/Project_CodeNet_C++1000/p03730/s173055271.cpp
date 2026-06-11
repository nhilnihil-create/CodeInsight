#include <iostream>
using namespace std;

/*
a%bの値は, aからa*bまでで一周する. (a%bとa*(b+1)%bの値, 2a%bとa*(b+2)%bの値はそれぞれ同じ)
よって, aをb回足す過程で各回a%bとcの値を比較し, b回経ってもfalseならfalse.
*/

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  
  bool can = false;
  for (int i = 1; i <= b; i++) {
    if ((a*i) % b == c) can = true;
  }
  
  cout << (can ? "YES" : "NO") << endl;
}