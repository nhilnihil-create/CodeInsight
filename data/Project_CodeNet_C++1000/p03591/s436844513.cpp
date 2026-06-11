#include <bits/stdc++.h>
using namespace std;
int main(){
  string a;
  cin >> a;
  string b = "YAKI";
  for (int i = 0; i < 4; i++) {
    if (a[i] != b[i]) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
}