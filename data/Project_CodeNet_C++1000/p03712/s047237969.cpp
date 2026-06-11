#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W ;
  vector<char> A(W);

  for (int q=0;q<W+2;q++){
    cout << "#" ;
  }  
  cout << endl;
  for (int i=0;i<H;i++){
    for (int j=0;j<W;j++){
      cin >> A.at(j);
    }
    cout << "#" ;
    for (int k=0;k<W;k++){
    cout << A.at(k);
    }
    cout << "#" << endl;
  }

  for (int l=0;l<(W+2);l++){
    cout << "#" ;
  }
  cout << endl;
}