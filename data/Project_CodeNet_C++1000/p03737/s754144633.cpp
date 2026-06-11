#include <bits/stdc++.h>
using namespace std;

string a, b, c;

int main () {
  cin >> a >> b >> c;
  // ini mengubah karakter pertama dari a menjadi kapital
  a[0] = a[0] - 'a' + 'A';  
  b[0] = b[0] - 'a' + 'A'; 
  c[0] = c[0] - 'a' + 'A'; 
  a=a[0];
  b=b[0];
  c=c[0];
  cout << a << b << c;

}