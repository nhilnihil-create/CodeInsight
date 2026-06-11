#include <bits/stdc++.h>
using namespace std;

int main() {
  int W, H, N;
  cin >> W >> H >> N;
  vector<vector<bool>>data(H,vector<bool>(W,true));
  for(int i=0;i<N;i++){
    int x, y, a;
    cin >> x >> y >> a;
    if(a==1){
      for(int j=0;j<H;j++){
        for(int k=0;k<x;k++){
          data.at(j).at(k)=false;
        }
      }
    }
    if(a==2){
      for(int j=0;j<H;j++){
        for(int k=x;k<W;k++){
          data.at(j).at(k)=false;
        }
      }
    }
    if(a==3){
      for(int j=0;j<y;j++){
        for(int k=0;k<W;k++){
          data.at(j).at(k)=false;
        }
      }
    }
    if(a==4){
      for(int j=y;j<H;j++){
        for(int k=0;k<W;k++){
          data.at(j).at(k)=false;
        }
      }
    }
  }
  int count=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(data.at(i).at(j)) count++;
    }
  }
  cout << count << endl;
}
