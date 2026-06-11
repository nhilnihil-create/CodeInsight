#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >> h >> w;
  
  int ih, iw;
  vector<string> vec;
  
  string sline = "";
  string kakomi = "#";
  string line;
  
  for (int i = 0; i < w + 2; i++) {
    sline += kakomi;
  }
  
  cout << sline << endl;
  for (int ih = 0; ih < h; ih++) {
    cin >> line;
    cout << kakomi + line + kakomi << endl;
  }
  cout << sline << endl;
}