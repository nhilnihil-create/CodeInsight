#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  
  for (int i = 0; i < w+2; i++) {
    cout << "#";
  }
  cout << endl;
  
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cout << "#";
    cin >> s.at(i);
    cout << s.at(i);
    cout << "#" << endl;
  }
  
  
  for (int i = 0; i < w+2; i++) {
    cout << "#";
  }
  cout << endl;
}