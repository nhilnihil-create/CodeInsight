#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, r;
  cin >> a >> b >> c;

  r = b+c;
  if (a+b <= a+c){
    if (a+b <= b+c) r = a+b;
  } else if (a+c <= b+c) r = a+c;

  cout << r << endl;
}