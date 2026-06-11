#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int A=-1,Z;
  for(int i=0;i<S.size();i++){
    if(S.at(i)=='A' && A==-1){
      A=i;
    }
    else if(S.at(i)=='Z'){
      Z=i;
    }
  }
  cout << Z-A+1 << endl;
}
  