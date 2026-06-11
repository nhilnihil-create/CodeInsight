#include<bits/stdc++.h>
using namespace std;
int main(){
  int H,W;
  cin >> H >> W;
  vector<string> A(H);
  for(int i = 0; i < H; i++){
    cin >> A.at(i);
  }
  for(int i = 0; i < H+2; i++){
    if( i == 0 || i == H+1 ){
      cout << string(W+2, '#') << endl;
    }else{
      cout << '#' + A.at(i-1) + '#' << endl;
    }
  }
}