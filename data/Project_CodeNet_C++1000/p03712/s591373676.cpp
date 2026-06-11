#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  vector<string> line(H);
  for(int i=0;i<H;i++){
    string tmp;
    cin >> tmp;
    line.at(i)=tmp;
  }
  for(int i=0;i<W+2;i++){
    cout << '#';
  }
  cout << endl;
  for(int i=0;i<H;i++){
    cout << '#' << line.at(i) << '#' << endl;
  }
  for(int i=0;i<W+2;i++){
    cout << '#';
  }
  cout << endl;
}