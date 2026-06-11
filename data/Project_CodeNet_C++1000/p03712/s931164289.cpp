#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  for(int i=0; i<=W+1; i++){
    if(i == W+1){
      cout << "#" << endl;
    }
    else{
    cout << "#";
    }
  }
  for(int i=0; i<H; i++){
    string S;
    cin >> S;
    cout << "#" << S << "#" << endl;
  }
    for(int i=0; i<=W+1; i++){
    if(i == W+1){
      cout << "#" << endl;
    }
    else{
    cout << "#";
    }
  }
}
