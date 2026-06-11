#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  vector<vector<string>> S(H,vector<string>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> S.at(i).at(j);
      if(S.at(i).at(j)=="snuke"){
        char C='A'+j;
        cout << C << i+1 << endl;
        break;
      }
    }
  }
}