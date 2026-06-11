#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int A=S.size();
  for(int i=0;i<A-1;i++){
    if(S.at(i)==S.at(i+1)){
      cout << i+1 << " " << i+2 << endl;
      return 0;
    }
  }
  for(int i=0;i<A-2;i++){
    if(S.at(i)==S.at(i+1) || S.at(i+1)==S.at(i+2) || S.at(i+2)==S.at(i)){
      cout << i+1 << " " << i+3 << endl;
      return 0;
    }
  }
  cout << -1 << " " << -1 << endl;
}
  
  