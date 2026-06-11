#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  string input;
  cin >> H>>W;
  string s;
  for(int i =0; i <W+2; i++){
    s += "#";
  }
  cout << s << endl;
  
  // 
  for (int i = 0; i < H; i++) {
    cin >> input;
    cout <<"#"+input+ "#"<< endl;
  }
  
  cout << s << endl;
  
}