#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int i=0,j=0;
  if(a==5) {
    ++i;
  } else if(a==7) {
    ++j;
  }
  if(b==5) {
    ++i;
  } else if(b==7) {
    ++j;
  }
  if(c==5) {
    ++i;
  } else if(c==7) {
    ++j;
  }
  if(i==2 && j==1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
