#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  string str,text;
  for(int i=0;i<W+2;i++){
    text+="#";
  }
  cout <<text <<endl;
  for(int i =0; i<H; i++){
    cin >>str;
    cout <<"#"+str+"#"<<endl;
  }
  cout <<text <<endl;
}
