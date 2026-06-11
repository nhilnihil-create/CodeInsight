//#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  
  string a[h];
  for(int i = 0; i < h; i++) {
    cin >> a[i];
  }
  
  for(int i = 0; i < w + 2; i++) {
    cout << "#";
  }
  cout << endl;
  
  for(int i = 0; i < h; i++) {
    cout << "#" << a[i] << "#" << endl;
  }
  
  for(int i = 0; i < w + 2; i++) {
    cout << "#";
  }
  cout << endl;
  return 0;
}
