#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;

  string str;
  for(int i=0; i<H+2; i++){
    cout << '#';
    if(i==0 || i==H+1){
      int n=0;
      while(n<W){
        cout << '#';
        n++;
        }
    }
    else{
      cin  >> str;
      cout << str;
    }
    cout << '#'<< endl;
  }
}