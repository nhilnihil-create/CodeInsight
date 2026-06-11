#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  string a,b;
  cin >> a >> b;
  for (int i=0;i<max(a.length(),b.length());i++) {
    if (a.length()>i) cout << a[i];
    if (b.length()>i) cout << b[i];
  }
}