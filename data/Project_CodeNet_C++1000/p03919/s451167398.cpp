#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  char alp[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      string in;
      cin >> in;
      if(in=="snuke"){
        cout << alp[j] << i+1 << endl;
      }
    }
  }
  return 0;
}