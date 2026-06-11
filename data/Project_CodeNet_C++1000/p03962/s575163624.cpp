#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
  int a,b,c;
  int num = 3;
  cin >> a >> b >> c;
  if (a == b) {
	num -= 1;
  	if (b == c) {
      num -= 1;
    }
  } else if (a == c) {
      num -= 1;
      if (b == c) {
        num -= 1;
      }
  } else if (b == c) {
      num -= 1;
      if (a == b) {
        num -= 1;
      }
  }   
  cout << num << endl;
  return 0;
}