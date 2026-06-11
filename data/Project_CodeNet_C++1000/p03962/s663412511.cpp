#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int a, b,  c;
  cin >> a >> b >> c;
  int count = 3;
  if(a == b) --count;
  if(a == c) --count;
  if(b == c) --count;
  if(a == b  && a == c) count = 1;
  cout << count << endl;
}
