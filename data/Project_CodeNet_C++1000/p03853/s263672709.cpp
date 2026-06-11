#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h, w;
  cin >> h >> w;
  
  vector<string> C(h);
  
  for (int i = 0; i < h; i++) {
    cin >> C.at(i);
  }

  vector<string> A(2*h);
  
  int s = 0;
  
  for (int i = 0; i < 2*h; i++) {
    s = i / 2;
    A.at(i) = C.at(s);
    cout << A.at(i) << endl;

  }
  
 
 
}
        