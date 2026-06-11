#include <bits/stdc++.h>
using namespace std;

int main(){
  int W,H,N;
  cin >> W >> H >> N;
  vector<int> X(N),Y(N),A(N);
  for(int i=0;i<N;i++){
    cin >> X.at(i) >> Y.at(i) >> A.at(i);
  }
  vector<vector<bool>> ans(H,vector<bool>(W,false));//falseは白
  for(int i=0;i<N;i++){
    if(A.at(i)==1){
      for(int j=0;j<H;j++){
        for(int k=0;k<X.at(i);k++){
          ans.at(j).at(k)=true;
        }
      }
    }
    else if(A.at(i)==2){
      for(int j=0;j<H;j++){
        for(int k=X.at(i);k<W;k++){
          ans.at(j).at(k)=true;
        }
      }
    }
    else if(A.at(i)==3){
      for(int j=0;j<Y.at(i);j++){
        for(int k=0;k<W;k++){
          ans.at(j).at(k)=true;
        }
      }
    }
    else{
      for(int j=Y.at(i);j<H;j++){
        for(int k=0;k<W;k++){
          ans.at(j).at(k)=true;
        }
      }
    }
  }
  int count=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(!ans.at(i).at(j)){
        count++;
      }
    }
  }
  cout << count << endl;
} 