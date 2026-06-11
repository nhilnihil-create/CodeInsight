#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  vector<string> vec(x);
  for (int i = 0; i < x; i++) {
    cin >> vec.at(i);
  }
  
  for (int i = 0; i < y + 2; i++) {
    cout << "#";
  }
  cout << endl;
  
  for (int i = 0; i < x; i++) {
    cout << "#" << vec.at(i) << "#" << endl;
  }
  
  for (int i = 0; i < y + 2; i++) {
    cout << "#";
  }
}