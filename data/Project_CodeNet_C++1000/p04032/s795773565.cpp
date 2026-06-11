#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int N=S.size();
  bool a=false;
  int A=-1,B=-1;
  for(int i=0;i<N-1;i++){
    if(S.at(i)==S.at(i+1)){
      A=i+1,B=i+2;
    }
  }
  for(int i=0;i<N-2;i++){
    if(S.at(i)==S.at(i+2)){
      A=i+1,B=i+3;
    }
  }
  cout << A << " " << B << endl;
}