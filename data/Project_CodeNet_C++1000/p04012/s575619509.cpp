#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string w;
  cin >> w;
  
  vector<int> vec(26, 0);
  for (int i = 0; i < w.size(); i++) {
    
    if (w.at(i) == 'a') vec.at(0)++;
    if (w.at(i) == 'b') vec.at(1)++;
    if (w.at(i) == 'c') vec.at(2)++;
    if (w.at(i) == 'd') vec.at(3)++;
    if (w.at(i) == 'e') vec.at(4)++;
    if (w.at(i) == 'f') vec.at(5)++;
    if (w.at(i) == 'g') vec.at(6)++;
    if (w.at(i) == 'h') vec.at(7)++;
    if (w.at(i) == 'i') vec.at(8)++;
    if (w.at(i) == 'j') vec.at(9)++;
    if (w.at(i) == 'k') vec.at(10)++;
    if (w.at(i) == 'l') vec.at(11)++;
    if (w.at(i) == 'm') vec.at(12)++;
    if (w.at(i) == 'n') vec.at(13)++;
    if (w.at(i) == 'o') vec.at(14)++;
    if (w.at(i) == 'p') vec.at(15)++;
    if (w.at(i) == 'q') vec.at(16)++;
    if (w.at(i) == 'r') vec.at(17)++;
    if (w.at(i) == 's') vec.at(18)++;
    if (w.at(i) == 't') vec.at(19)++;
    if (w.at(i) == 'u') vec.at(20)++;
    if (w.at(i) == 'v') vec.at(21)++;
    if (w.at(i) == 'w') vec.at(22)++;
    if (w.at(i) == 'x') vec.at(23)++;
    if (w.at(i) == 'y') vec.at(24)++;
    if (w.at(i) == 'z') vec.at(25)++;
  }
  
  bool ans = true;
  for (int x : vec) {
    if (x % 2 != 0) ans = false;
  }
  
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
    
}