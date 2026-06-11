#include<bits/stdc++.h>
using namespace std;

int main() {
  int X=0,max_X=0,N;
  cin >> N;
  string S;
  cin >> S;
  for(int i=0;i<N;i++){
    if(S.at(i)=='I'){
      X++;
    }
    else{
      X--;
    }
    max_X=max(max_X,X);
  }
  cout << max_X << endl;
}