#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  string a,b;
  cin >> a >> b;
  
  int s = a.size();
  int t = b.size();

  if(s > t) cout << "GREATER" << endl;
  else if(s < t) cout << "LESS" << endl;
  else {
    if(a[0] > b[0]) cout << "GREATER" << endl;
    else if(a[0] < b[0]) cout << "LESS" << endl;
    else cout << "EQUAL" << endl;
  }
}