#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int W, H, N;
  cin >> W >> H >> N;
  vector<vector<int>> color(H, vector<int>(W,0));
  int x, y, a;
  int area=0;
  for(int i=0; i<N; i++){
    cin >> x >> y >> a;
    if(a==1){
      for(int j=0; j<x; j++){
        for(int k=0; k<H; k++){
          color.at(k).at(j)=1;
        }
      }
    }else if(a==2){
      for(int j=x; j<W; j++){
        for(int k=0; k<H; k++){
          color.at(k).at(j)=1;
        }
      }
    }else if(a==3){
      for(int j=0; j<W; j++){
        for(int k=0; k<y; k++){
          color.at(k).at(j)=1;
        }
      }
    }else if(a==4){
      for(int j=0; j<W; j++){
        for(int k=y; k<H; k++){
          color.at(k).at(j)=1;
        }
      }
    }else{
      cout << "error" <<endl;
    }
  }
  for(int j=0; j<W; j++){
    for(int k=0; k<H; k++){
      if(color.at(k).at(j)==0){
        area++;
      }
    }
  } 
  cout << area << endl;
}
