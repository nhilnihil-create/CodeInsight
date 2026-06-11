#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
  int H, W, N;
  cin >> H >> W >> N;
  vector<int> a(N);
  for(int i=0; i<N; i++) cin >> a.at(i);
  int m[H][W];
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++) m[i][j]=0;
  }
  int cnt=0;
  int temp=1;
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(i%2==0){
        m[i][j]=cnt+1;
      }
      else{
        m[i][W-j-1]=cnt+1;
      }
      if(temp!=a.at(cnt)) temp++;
      else{
        temp=1;
        cnt++;
      }
    }
  }
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++) cout << m[i][j] << ' ';
    cout << endl;
  }
}