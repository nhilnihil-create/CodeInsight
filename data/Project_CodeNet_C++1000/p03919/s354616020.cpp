#include <bits/stdc++.h>
using namespace std;
int main(){
  int h,w,H,W;
  string s,t="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  cin >> h >> w;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> s;
      if(s=="snuke"){
        H=i+1;W=j;
      }
    }
  }
  cout << t[W] << H << endl;
  return 0;
}