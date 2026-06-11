#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int h,w;
  cin >> h >> w;
  char data[2*h][w];
  for(int i=0;i<2*h;i+=2){
    for(int j=0;j<w;j++){
      cin >> data[i][j];
      data[i+1][j]=data[i][j];
    }
  }
  for(int i=0;i<2*h;i++){
    for(int j=0;j<w;j++){
      cout << data[i][j];
    }
    cout << endl;
  }
}
