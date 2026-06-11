#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  
  string a_ij;
  vector<string> line(W+2,"#");
  
  for (int i=0;i<W+2;i++)
    cout << line.at(i); cout << endl;
  
  for (int i=0;i<H;i++){
    cout << "#";
    cin >> a_ij;
    for (int j=0;j<W;j++){
      cout << a_ij.at(j);
    }
    cout << "#" << endl;
  }
  for (int i=0;i<W+2;i++)
    cout << line.at(i); cout << endl;
}