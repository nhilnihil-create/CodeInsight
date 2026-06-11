#include<bits/stdc++.h>
using namespace std;

int main(){
  int i, j, H, W;
  string s;
  bool flag = false;
  cin >> H >> W;
  for(int k=1; k<=H; k++){
    for(int l=0; l<W; l++){
      cin >> s;
      if(s=="snuke"){
        i=k;
        j=l;
      }
    }
  }
  cout << (char)('A'+j) << i << endl;
  return 0;
}