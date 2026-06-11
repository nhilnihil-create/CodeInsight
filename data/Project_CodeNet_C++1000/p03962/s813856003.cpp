#include <iostream>

using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  int cnt = 1;
  if((a == b) && (a == c)) {
    cnt = 1;
  } else if((a != b) && (a != c) && (b != c)) {
    cnt = 3;
  } else {
    cnt = 2;
  }
  cout << cnt << endl;
  return 0;
}