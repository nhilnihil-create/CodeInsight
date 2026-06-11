#include <bits/stdc++.h>
using namespace std;
int main(){
  string a;
  cin >> a;
  int x = 0;
  string b = "CODEFESTIVAL2016";
  for (int i = 0; i < a.size(); i++) {
    if (a[i] != b[i]) {
      x++;
    }
  }
  cout << x;
}