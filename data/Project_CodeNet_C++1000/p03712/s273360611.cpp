#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;  
  vector <char> vec(W+2,'#');
  
  for (int i=0;i<H+2;i++) {
    if (i==0||i==H+1){
      vec=vector<char>(W+2,'#');
      for (int j=0;j<W+2;j++) {
        cout << vec.at(j);
      }
      cout << endl;
    }
    
    else {
      for (int j=0;j<W;j++) {
        cin >> vec.at(j+1);
      }
      for (int j=0;j<W+2;j++) {
        cout << vec.at(j);
      }
      cout << endl;
    }  
  }  
}
