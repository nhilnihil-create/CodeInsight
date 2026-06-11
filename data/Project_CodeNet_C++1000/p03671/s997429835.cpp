#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int a,b,c;
  cin >> a >> b >> c;

  if(a <= b & b <= c)
    cout << a+b << endl; 
  else if(a <= c & c <= b)
    cout << a+c << endl; 
  else if(b <= c & c <= a)
    cout << b+c << endl;
  else if(b <= a & a <= c)
    cout << b+a << endl;
  else if(c <= a & a <= b)
    cout << a+c << endl;
  else if(c <= b & b <= a)
    cout << c+b << endl;
  
}