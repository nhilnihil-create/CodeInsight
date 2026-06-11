#include <bits/stdc++.h>
using namespace std;
 

int main() {
  vector<int> hoge(3);
  for (int i = 0; i < 3; i++) {
    cin >> hoge.at(i);
  }
  
  int five = 0;
  int seven = 0;
  for (int i = 0; i < 3; i++) {
    if (hoge.at(i) == 5) {
      five++;
    } else if (hoge.at(i) == 7) {
      seven++;
    }
  }
    
  if (five == 2 && seven == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  
  return 0;
}