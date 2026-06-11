#include<bits/stdc++.h>
using namespace std;

int main(){
  int W,H,N;
  cin >> W >> H >> N;
  vector<vector<int>> B(H,vector<int>(W,0));
  vector<int> X(N),Y(N),A(N);
  for(int i=0;i<N;i++){
    cin >> X.at(i) >> Y.at(i) >> A.at(i);
  }
  for(int i=0;i<N;i++){
    if(A.at(i)==1){
      for(int j=0;j<H;j++){
        for(int k=0;k<X.at(i);k++){
          B.at(j).at(k)++;
        }
      }
    }
    else if(A.at(i)==2){
       for(int j=0;j<H;j++){
        for(int k=X.at(i);k<W;k++){
          B.at(j).at(k)++;
        }
       }
    }
    else if(A.at(i)==3){
       for(int j=0;j<Y.at(i);j++){
        for(int k=0;k<W;k++){
          B.at(j).at(k)++;
        }
       }
    }
    else if(A.at(i)==4){
       for(int j=Y.at(i);j<H;j++){
        for(int k=0;k<W;k++){
          B.at(j).at(k)++;
        }
       }
    }
  }
  int count=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(B.at(i).at(j)==0){
        count++;
      }
    }
  }
  cout << count << endl;
}     