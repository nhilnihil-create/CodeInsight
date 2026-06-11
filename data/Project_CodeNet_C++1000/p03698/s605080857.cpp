#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  int sum=0;
  cin >> S;
  for(int i=0;i<S.size();i++){
    for(int j=0;j<i;j++){
      if(S[i]==S[j]){
        sum++;
      }
    }
  }
  if(sum>0){
    cout << "no" << endl;
  }else{
    cout << "yes" << endl;
  }
  return 0;
}