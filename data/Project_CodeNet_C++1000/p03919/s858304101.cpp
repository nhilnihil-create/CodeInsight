#include <iostream>
using namespace std;

int main() {
  int h, w, b;
  char a;
  cin >> h >> w;

  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      string s;
      cin >> s;

      if (s=="snuke") {
        a=65+j;
        b=i+1;
      } 
    }
  }

  cout << a << b;
}