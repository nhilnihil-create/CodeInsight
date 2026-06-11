#include<bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<string> S(H*W);
  int w=0;
  int h=0;
  for(int i=0; i<H*W; i++){
    cin >> S.at(i);
    if(S.at(i)=="snuke"){
      h=i/W+1;
      w=i%W;
      break;
    }
  }
  char A='A';
  char Ans='A'+w;
  cout << Ans << h << endl;
}