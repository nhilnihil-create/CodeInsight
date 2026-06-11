#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h,w = 0;
  cin >> h >> w;
  
  vector<string> str(h);
  for(int i=0;i<h;i++){
    cin >> str.at(i);
  }
  
  for(int i=0;i<w+2;i++){
    cout << "#";
  }
  cout << endl;
  for(int i=0;i<h;i++){
    cout << "#" + str.at(i) + "#" << endl;
  }

  for(int i=0;i<w+2;i++){
    cout << "#";
  }
  cout << endl;
  
}