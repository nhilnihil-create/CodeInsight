#include<bits/stdc++.h>
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  
  int c, r;
  
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
      string s;
      cin >> s;
      if(s == "snuke"){
        c = j;
        r = i;
      }
    }
  }
  
  cout << (char)('A'+c) << r+1 << endl;
  
  return 0;
}
