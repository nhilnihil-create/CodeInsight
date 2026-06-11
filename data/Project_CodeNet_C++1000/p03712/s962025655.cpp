#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  cin >> H >> W;
  vector<string>vec(H);
string O;
  O = "##";
  for(int i=0; i<W; i++){
    O+="#";}
  cout << O <<endl; 
  for(int j=0;j<H;j++){
    cin>> vec.at(j);
    cout << '#'+vec.at(j)+'#'<< endl;
  }
  cout << O << endl;
}