#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#include <iostream>
#include <set>
 
int main(void){
  int w,h,n;cin >> w >> h >> n;
  vector<vector<int>> rect(w,vector<int>(h,false));
  int x,y,a;
  for(int i=0;i<n;i++){
    cin >> x >> y >> a;
    if(a==1 || a==2){
      for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
          if(a==1){
            rect[j][i] |= (j<x);
          } else {
            rect[j][i] |= (j>=x);
          }
        }
      }
    } else {
      for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
          if(a==3){
            rect[i][j] |= (j<y);
          } else {
            rect[i][j] |= (j>=y);
          }
        }
      }
    }
  }
  
  int area=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(!rect[j][i]) area++;
    }
  }
  
  cout << area << endl;
  return 0;
}