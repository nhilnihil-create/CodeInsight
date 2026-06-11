#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<char> A(W+2,'#');
  for(int i=0;i<W+2;i++){
    cout << A.at(i);
  }
  cout << endl;
  for(int i=0;i<H;i++){
    vector<string> B(3);
    string x;
    cin >> x;
    B.at(0)="#";
    B.at(1)=x;
    B.at(2)="#";
    
    for(int j=0;j<3;j++){
      cout << B.at(j);
    }
    cout << endl;
  }
  
  for(int i=0;i<W+2;i++){
    cout << A.at(i);
  }
} 

  