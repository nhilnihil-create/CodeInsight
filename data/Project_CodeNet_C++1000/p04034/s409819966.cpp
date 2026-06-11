#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  vector<int> X(M),Y(M);
  for(int i=0;i<M;i++){
    cin >> X.at(i) >> Y.at(i);
  }
  vector<bool> red(N,false);
  red.at(0)=true;
  vector<int> num(N,1);
  for(int i=0;i<M;i++){
    num.at(X.at(i)-1)--;
    num.at(Y.at(i)-1)++;
    if(red.at(X.at(i)-1)){
      red.at(Y.at(i)-1)=true;
    }
    if(num.at(X.at(i)-1)==0){
      red.at(X.at(i)-1)=false;
    }
  }
  int count=0;
  for(int i=0;i<N;i++){
    if(red.at(i)){
      count++;
    }
  }
  cout << count << endl;
}